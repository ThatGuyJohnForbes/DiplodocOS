kernel_src := $(shell find src/kernel -name *.cpp)
kernel_obj := $(patsubst src/kernel/%.cpp, build/kernel/%.o, $(kernel_src))

x86_64_cpp_src := $(shell find src/x86_64 -name *.cpp)
x86_64_cpp_obj := $(patsubst src/x86_64/%.cpp, build/x86_64/%.o, $(x86_64_cpp_src))

x86_64_asm_src := $(shell find src/x86_64 -name *.asm)
x86_64_asm_obj := $(patsubst src/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_src))

x86_64_obj := $(x86_64_cpp_obj) $(x86_64_asm_obj)

$(kernel_obj): build/kernel/%.o : src/kernel/%.cpp
	mkdir -p $(dir $@) && \
	x86_64-elf-g++ -c -I src/intf -ffreestanding $(patsubst build/kernel/%.o, src/kernel/%.cpp, $@) -o $@

$(x86_64_cpp_obj): build/x86_64/%.o : src/x86_64/%.cpp
	mkdir -p $(dir $@) && \
	x86_64-elf-g++ -c -I src/intf -ffreestanding $(patsubst build/x86_64/%.o, src/x86_64/%.cpp, $@) -o $@

$(x86_64_asm_obj): build/x86_64/%.o : src/x86_64/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/x86_64/%.asm, $@) -o $@

.PHONY: build-x86_64
build-x86_64: $(kernel_obj) $(x86_64_obj)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_obj) $(x86_64_obj) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso