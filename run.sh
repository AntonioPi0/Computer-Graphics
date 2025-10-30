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
BUILD_ROOT=".build"
WORK_DIR="${BUILD_ROOT}/${VARIANT_ID}"

mkdir -p "$WORK_DIR"

rsync -a --delete "$BASE_DIR/" "$WORK_DIR/"

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
make -j"$(nproc --all 2>/dev/null || echo 1)"
./viewer/myViewer
popd >/dev/null
