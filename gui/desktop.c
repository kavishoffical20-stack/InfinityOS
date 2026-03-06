#include "desktop.h"
#include "window_manager.h"
#include "../drivers/display.h"

static gfx_context_t* g_ctx;

void desktop_init(void) {
    g_ctx = 0;
}

void desktop_draw(void) {
    if (!g_ctx) {
        return;
    }
    display_present(g_ctx);
}
