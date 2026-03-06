; InfinityOS Multiboot-compliant bootloader
BITS 32

MB_MAGIC    equ 0x1BADB002
MB_FLAGS    equ 0x00010003          ; align modules + mem info + video mode request
MB_CHECKSUM equ -(MB_MAGIC + MB_FLAGS)

section .multiboot
align 4
    dd MB_MAGIC
    dd MB_FLAGS
    dd MB_CHECKSUM
    dd 0, 0, 0, 0, 0                ; a.out kludge fields (unused)
    dd 0                            ; mode_type: linear graphics if available
    dd 1024                         ; width
    dd 768                          ; height
    dd 32                           ; depth

section .text
global start
extern kmain

start:
    cli
    mov esp, stack_top
    push ebx                        ; multiboot info pointer
    push eax                        ; multiboot magic
    call kmain
.hang:
    hlt
    jmp .hang

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:
