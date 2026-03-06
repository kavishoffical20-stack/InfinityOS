# InfinityOS

InfinityOS is a hobby operating-system prototype with a modern desktop shell inspired by Windows 10/11 UI concepts.

## Features

- **Windows 11 style desktop shell** with layered panels and modern color palette
- **Taskbar** inspired by Windows 10/11 with Start button area
- **Start menu** with app list (File Manager, Terminal, Settings)
- **Window manager** with title bars and minimize/maximize/close controls
- **File manager app** backed by an in-memory modular file system
- **Terminal app** with keyboard input buffering
- **Settings app** with system action hooks
- **Keyboard + mouse input pipeline** via modular drivers
- **Modular drivers** for keyboard, mouse, display, and sound
- **Cooperative multitasking scheduler** for app tasks

## Project Structure

```text
boot/
kernel/
drivers/
gui/
system/
apps/
```

## Build Requirements

Install the following tools:

- GCC with 32-bit support (`gcc`, `ld`)
- NASM (`nasm`)
- GRUB tools (`grub-mkrescue`)
- QEMU for emulation (`qemu-system-i386`, optional)

On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install build-essential gcc-multilib nasm grub-pc-bin xorriso qemu-system-x86
```

## Build using GCC and NASM

```bash
./build.sh
```

or manually:

```bash
make clean
make all
```

## Create a Bootable ISO

```bash
make iso
```

This creates:

- Kernel binary: `build/infinityos.bin`
- Bootable ISO: `build/infinityos.iso`

## Run the ISO in QEMU

```bash
make run
```

## Notes

- `boot/boot.asm` provides a Multiboot bootloader entry in Assembly.
- `kernel/kmain.c` initializes drivers, filesystem, scheduler, and GUI.
- GUI rendering uses a small custom graphics layer in `kernel/graphics.c`.
- Filesystem and multitasking are simplified educational implementations.
