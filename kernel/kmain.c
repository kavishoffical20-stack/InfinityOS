#include "include/kernel.h"
#include "include/graphics.h"
#include "include/scheduler.h"
#include "../drivers/display.h"
#include "../drivers/sound.h"
#include "../system/filesystem.h"
#include "../system/input.h"
#include "../gui/window_manager.h"
#include "../gui/start_menu.h"

extern void app_file_manager_bootstrap(void);
extern void app_terminal_tick(void);
extern void app_settings_apply_defaults(void);

typedef struct {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint8_t syms[12];
    uint32_t mmap_length;
    uint32_t mmap_addr;
    uint32_t drives_length;
    uint32_t drives_addr;
    uint32_t config_table;
    uint32_t boot_loader_name;
    uint32_t apm_table;
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint16_t vbe_mode;
    uint16_t vbe_interface_seg;
    uint16_t vbe_interface_off;
    uint16_t vbe_interface_len;
    uint64_t framebuffer_addr;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t framebuffer_bpp;
    uint8_t framebuffer_type;
} __attribute__((packed)) multiboot_info_t;

static gfx_context_t g_ctx;

static void boot_ui(void) {
    gfx_clear(&g_ctx, 0x000E1116);
    wm_create_window("File Manager", 90, 70, 520, 420);
    wm_create_window("Terminal", 220, 140, 640, 380);
    wm_create_window("Settings", 740, 90, 240, 260);
    wm_draw();
}

void kmain(uint32_t multiboot_magic, uint32_t multiboot_info) {
    (void)multiboot_magic;
    multiboot_info_t* mbi = (multiboot_info_t*)multiboot_info;

    uint32_t* framebuffer = (uint32_t*)(uintptr_t)mbi->framebuffer_addr;
    gfx_init(&g_ctx, framebuffer, mbi->framebuffer_width, mbi->framebuffer_height,
             mbi->framebuffer_pitch, mbi->framebuffer_bpp);

    display_init(&g_ctx);
    input_init();
    sound_init();
    fs_init();
    scheduler_init();

    app_file_manager_bootstrap();
    app_settings_apply_defaults();

    wm_init(&g_ctx);
    boot_ui();

    scheduler_add_task("terminal", app_terminal_tick);

    for (;;) {
        scheduler_tick();
    }
}
