FROM ubuntu:latest
#crosscompiling script by wby boss : https://www.programmersought.com/article/28294693223/
RUN apt-get update && apt-get install -y software-properties-common

RUN add-apt-repository ppa:ubuntu-toolchain-r/test && dpkg --add-architecture i386
RUN apt-get update
RUN apt-get upgrade -y

#download i686 cross compilers
RUN apt-get install -y gcc-7 g++-7
RUN ln -s /usr/bin/gcc-7 /usr/bin/gcc
RUN ln -s /usr/bin/g++-7 /usr/bin/g++

RUN apt-get install -y nasm xorriso grub-pc-bin grub-common build-essential wget tar make gcc-multilib libc-dev libc6-dev-mipsel-cross libc6-dev
RUN apt-get update
#make should be in build-essential but i'm paranoid

RUN wget 'https://ftp.gnu.org/gnu/binutils/binutils-2.30.tar.xz'
RUN wget 'https://ftp.gnu.org/gnu/gcc/gcc-7.3.0/gcc-7.3.0.tar.xz'
RUN tar -xvJf binutils-2.30.tar.xz
RUN tar -xvJf gcc-7.3.0.tar.xz

RUN cd gcc-7.3.0 && ./contrib/download_prerequisites && cd ..
# This command will download related dependencies from foreign websites. If you cannot download, please solve the network problem yourself

RUN export PREFIX="/usr/local"
RUN export TARGET=i686-elf
RUN LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:$LIBRARY_PATH && export LIBRARY_PATH

#compile binutils for crosscompiling
RUN mkdir build-binutils && cd build-binutils && \
 ../binutils-2.30/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror --without-headers && \
 make && make install-strip && cd ..

 # Option description
# --disable-nls tells binutils not to include native language support. AKA only english
# --with-sysroot tells binutils to enable sysroot support in the cross-compiler by pointing it to a default empty directory.

#compile gcc for crosscompiling
RUN mkdir build-gcc && cd build-gcc && \
 ../gcc-7.3.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --with-multilib-list=m32 --without-headers && \
 make all-gcc && cd ..
RUN cd build-gcc && make all-target-libgcc && make install-strip-gcc && make install-strip-target-libgcc && cd ..

# Option description
# --disable-nls is the same as for binutils above.
# --without-headers tells GCC not to rely on any C library (standard or runtime) being present for the target.
# --enable-languages tells GCC not to compile all the other language frontends it supports, but only C and C++.


VOLUME /root/env
WORKDIR /root/env