#include "start_menu.h"
#include "window_manager.h"

static int start_open;

void start_menu_toggle(void) {
    start_open = !start_open;
}

void start_menu_draw(void) {
    gfx_context_t* g_ctx = wm_context();
    if (!start_open || !g_ctx) {
        return;
    }

    uint32_t menu_h = 420;
    uint32_t x = 18;
    uint32_t y = g_ctx->height - 56 - menu_h;

    gfx_draw_rect(g_ctx, x, y, 360, menu_h, 0x0023262C);
    gfx_draw_text(g_ctx, x + 18, y + 20, "InfinityOS", 0x00FFFFFF);
    gfx_draw_text(g_ctx, x + 18, y + 56, "Apps", 0x00C7CFD9);
    gfx_draw_text(g_ctx, x + 18, y + 90, "- File Manager", 0x00FFFFFF);
    gfx_draw_text(g_ctx, x + 18, y + 120, "- Terminal", 0x00FFFFFF);
    gfx_draw_text(g_ctx, x + 18, y + 150, "- Settings", 0x00FFFFFF);
}
