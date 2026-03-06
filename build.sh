#!/usr/bin/env bash
set -euo pipefail

make clean
make all
make iso

echo "Build complete:"
echo "  Kernel: build/infinityos.bin"
echo "  ISO:    build/infinityos.iso"
