#include "filesystem.h"
#include "../kernel/include/kernel.h"

static fs_file_t files[FS_MAX_FILES];

void fs_init(void) {
    for (size_t i = 0; i < FS_MAX_FILES; ++i) {
        files[i].used = 0;
    }
}

static int find_slot(const char* name) {
    for (int i = 0; i < FS_MAX_FILES; ++i) {
        if (files[i].used && kstrlen(name) == kstrlen(files[i].name)) {
            int same = 1;
            for (size_t c = 0; c < kstrlen(name); ++c) {
                if (files[i].name[c] != name[c]) {
                    same = 0;
                    break;
                }
            }
            if (same) return i;
        }
    }
    return -1;
}

int fs_create(const char* name, const char* contents) {
    for (int i = 0; i < FS_MAX_FILES; ++i) {
        if (!files[i].used) {
            files[i].used = 1;
            size_t nlen = kstrlen(name);
            size_t clen = kstrlen(contents);
            if (nlen >= FS_MAX_NAME) nlen = FS_MAX_NAME - 1;
            if (clen >= FS_MAX_DATA) clen = FS_MAX_DATA - 1;
            kmemcpy(files[i].name, name, nlen);
            files[i].name[nlen] = '\0';
            kmemcpy(files[i].data, contents, clen);
            files[i].data[clen] = '\0';
            files[i].size = clen;
            return i;
        }
    }
    return -1;
}

int fs_read(const char* name, char* out, size_t out_size) {
    int idx = find_slot(name);
    if (idx < 0 || out_size == 0) {
        return -1;
    }

    size_t copy = files[idx].size;
    if (copy >= out_size) copy = out_size - 1;
    kmemcpy(out, files[idx].data, copy);
    out[copy] = '\0';
    return (int)copy;
}

int fs_list(const char** names, size_t max_names) {
    size_t count = 0;
    for (size_t i = 0; i < FS_MAX_FILES && count < max_names; ++i) {
        if (files[i].used) {
            names[count++] = files[i].name;
        }
    }
    return (int)count;
}
