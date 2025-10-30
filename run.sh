#!/bin/bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <variant-number>" >&2
    echo " 1 -> TP1 variant" >&2
    echo " 2 -> TP2 variant" >&2
    echo " 3 -> TP3 variant" >&2
    exit 1
fi

case "$1" in
    1|2|3)
        VARIANT_ID="tp$1"
        ;;
    *)
        echo "Unknown variant: $1" >&2
        exit 1
        ;;
esac

BASE_DIR="base"
VARIANT_DIR="variants/${VARIANT_ID}"
SHADER_SOURCE="tp/${VARIANT_ID}.comp"
BUILD_ROOT="build"

mkdir -p "$BUILD_ROOT"

for id in tp1 tp2 tp3; do
    mkdir -p "${BUILD_ROOT}/${id}"
done

WORK_DIR="${BUILD_ROOT}/${VARIANT_ID}"

compute_base_signature() {
    if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
        git ls-tree -r HEAD base --full-tree | sha1sum | awk '{print $1}'
    else
        find "$BASE_DIR" -type f -print0 | sort -z | xargs -0 sha1sum | sha1sum | awk '{print $1}'
    fi
}

BASE_SIG_FILE="${WORK_DIR}/.base_signature"
CURRENT_SIG=$(compute_base_signature)

if [ ! -f "$BASE_SIG_FILE" ] || [ "$CURRENT_SIG" != "$(cat "$BASE_SIG_FILE" 2>/dev/null)" ]; then
    rsync -a --delete "$BASE_DIR/" "$WORK_DIR/"
    printf '%s' "$CURRENT_SIG" > "$BASE_SIG_FILE"
fi

if [ -d "$VARIANT_DIR" ]; then
    rsync -a "$VARIANT_DIR/" "$WORK_DIR/"
fi

if [ -s "$SHADER_SOURCE" ]; then
    cp "$SHADER_SOURCE" "$WORK_DIR/viewer/shaders/gpgpu_fullrt.comp"
fi

pushd "$WORK_DIR" >/dev/null
if [ ! -f Makefile ] || [ GPGPU_TP.pro -nt Makefile ] || [ viewer/viewer.pro -nt viewer/Makefile ]; then
    qmake -qt5
fi
make -j"$(command -v nproc >/dev/null 2>&1 && nproc --all || echo 1)"
./viewer/myViewer
popd >/dev/null
