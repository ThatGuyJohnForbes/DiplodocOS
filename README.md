# DiplodocOS
Learning the intricacies of the GNU/Linux kernel by attempting to make a deliberately vulnerable kernel that hopefully one day will have the same APIs as the GNU/Linux kernel, and as such could run a Linux distro over it.

Commands for building on windows
>docker run --rm -it -v "%cd%":/root/env diplodocos_buildenv
>
>make build-x86_64

Command for running on windows
>qemu-system-x86_64 dist/x86_64/kernel.iso
