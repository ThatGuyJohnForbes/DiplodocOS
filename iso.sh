#!/usr/bin/env bash
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/diplodocos.kernel isodir/boot/diplodocos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "diplodocos" {
	multiboot /boot/diplodocos.kernel
}
EOF
grub-mkrescue -o diplodocos.iso isodir
