#!/bin/bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <tp-number>" >&2
    exit 1
fi

TP_CHOICE=$1
PROJECT_ROOT="TP2"
VIEWER_DIR="$PROJECT_ROOT/viewer"
SHADER_TARGET="$VIEWER_DIR/shaders/gpgpu_fullrt.comp"

case "$TP_CHOICE" in
    1) SHADER_SOURCE="tp/tp1.comp" ;;
    2) SHADER_SOURCE="tp/tp2.comp" ;;
    3) SHADER_SOURCE="tp/tp3.comp" ;;
    *) echo "Unknown TP choice: $TP_CHOICE" >&2; exit 1 ;;
esac

cp "$SHADER_SOURCE" "$SHADER_TARGET"

pushd "$PROJECT_ROOT" >/dev/null
qmake -qt5
make
./viewer/myViewer
popd >/dev/null
