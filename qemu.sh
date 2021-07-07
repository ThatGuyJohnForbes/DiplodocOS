#!/usr/bin/env bash
set -e
. ./iso.sh

qemu-system-$(./target_triplet_to_arch.sh $HOST) -cdrom diplodocos.iso