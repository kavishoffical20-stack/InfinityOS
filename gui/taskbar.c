#include "taskbar.h"
#include "window_manager.h"

void taskbar_draw(void) {
    gfx_context_t* g_ctx = wm_context();
    if (!g_ctx) {
        return;
    }
    uint32_t y = g_ctx->height - 56;
    gfx_draw_rect(g_ctx, 0, y, g_ctx->width, 56, 0x00181A1E);
    gfx_draw_rect(g_ctx, 18, y + 10, 120, 36, 0x002257E0);
    gfx_draw_text(g_ctx, 32, y + 20, "Start", 0x00FFFFFF);
}
