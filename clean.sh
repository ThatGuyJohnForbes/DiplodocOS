#!/usr/bin/env bash
set -e
. ./config.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE clean)
done

rm -rf sysroot
rm -rf isodir
rm -rf diplodocos.iso