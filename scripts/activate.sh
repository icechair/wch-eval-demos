#!/bin/sh
prefix="$(pwd)/toolchain"
echo "setting path for toolchain: $prefix"
PATH="$prefix/gcc/bin:$prefix/openocd/bin:$PATH"
