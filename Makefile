ARCH=i386
CC=gcc
LD=ld
AS=nasm
CFLAGS=-m32 -ffreestanding -fno-stack-protector -fno-pic -nostdlib -Wall -Wextra -Ikernel/include
LDFLAGS=-m elf_i386 -T kernel/linker.ld

C_SOURCES=$(shell find kernel drivers gui system apps -name '*.c')
C_OBJECTS=$(patsubst %.c,build/%.o,$(C_SOURCES))
BOOT_OBJECT=build/boot/boot.o
KERNEL_BIN=build/infinityos.bin
ISO_ROOT=build/isodir

all: $(KERNEL_BIN)

$(BOOT_OBJECT): boot/boot.asm
	@mkdir -p $(dir $@)
	$(AS) -f elf32 $< -o $@

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL_BIN): $(BOOT_OBJECT) $(C_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

iso: $(KERNEL_BIN)
	mkdir -p $(ISO_ROOT)/boot/grub
	cp $(KERNEL_BIN) $(ISO_ROOT)/boot/infinityos.bin
	cp boot/grub/grub.cfg $(ISO_ROOT)/boot/grub/grub.cfg
	grub-mkrescue -o build/infinityos.iso $(ISO_ROOT)

run: iso
	qemu-system-i386 -cdrom build/infinityos.iso

clean:
	rm -rf build

.PHONY: all iso run clean
