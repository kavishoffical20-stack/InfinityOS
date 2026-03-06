#ifndef INFINITYOS_FILESYSTEM_H
#define INFINITYOS_FILESYSTEM_H

#include <stddef.h>

#define FS_MAX_FILES 64
#define FS_MAX_NAME  32
#define FS_MAX_DATA  4096

typedef struct {
    char name[FS_MAX_NAME];
    size_t size;
    char data[FS_MAX_DATA];
    int used;
} fs_file_t;

void fs_init(void);
int fs_create(const char* name, const char* contents);
int fs_read(const char* name, char* out, size_t out_size);
int fs_list(const char** names, size_t max_names);

#endif
