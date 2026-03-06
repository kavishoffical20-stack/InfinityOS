#ifndef INFINITYOS_KERNEL_H
#define INFINITYOS_KERNEL_H

#include <stdint.h>
#include <stddef.h>

void kmain(uint32_t multiboot_magic, uint32_t multiboot_info);

void* kmemset(void* dst, int value, size_t size);
void* kmemcpy(void* dst, const void* src, size_t size);
size_t kstrlen(const char* s);

#endif
