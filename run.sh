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
WORK_DIR=$(mktemp -d -t tp-build-XXXXXX)
cleanup() {
    rm -rf "$WORK_DIR"
}
trap cleanup EXIT

rsync -a "$BASE_DIR/" "$WORK_DIR/"

if [ -d "$VARIANT_DIR" ]; then
    rsync -a "$VARIANT_DIR/" "$WORK_DIR/"
fi

if [ -f "$SHADER_SOURCE" ]; then
    cp "$SHADER_SOURCE" "$WORK_DIR/viewer/shaders/gpgpu_fullrt.comp"
fi

pushd "$WORK_DIR" >/dev/null
qmake -qt5
make
./viewer/myViewer
popd >/dev/null
