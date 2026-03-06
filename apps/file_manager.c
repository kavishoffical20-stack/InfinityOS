#include "../system/filesystem.h"

void app_file_manager_bootstrap(void) {
    fs_create("readme.txt", "Welcome to InfinityOS File Manager");
    fs_create("notes.txt", "This is a modular demo file system.");
}
