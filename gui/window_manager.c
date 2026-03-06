#include "window_manager.h"
#include "taskbar.h"
#include "start_menu.h"

static gfx_context_t* g_ctx;
static wm_window_t windows[WM_MAX_WINDOWS];
static uint32_t window_count;

void wm_init(gfx_context_t* ctx) {
    g_ctx = ctx;
    window_count = 0;
    for (uint32_t i = 0; i < WM_MAX_WINDOWS; ++i) {
        windows[i].visible = 0;
    }
}

gfx_context_t* wm_context(void) {
    return g_ctx;
}

uint32_t wm_create_window(const char* title, int32_t x, int32_t y, uint32_t w, uint32_t h) {
    if (window_count >= WM_MAX_WINDOWS) {
        return (uint32_t)-1;
    }

    wm_window_t* win = &windows[window_count];
    win->id = window_count;
    win->title = title;
    win->x = x;
    win->y = y;
    win->width = w;
    win->height = h;
    win->minimized = 0;
    win->maximized = 0;
    win->visible = 1;
    return window_count++;
}

void wm_minimize(uint32_t id) {
    if (id < window_count) {
        windows[id].minimized = 1;
    }
}

void wm_maximize(uint32_t id) {
    if (id < window_count) {
        windows[id].maximized = 1;
        windows[id].x = 0;
        windows[id].y = 0;
        windows[id].width = g_ctx->width;
        windows[id].height = g_ctx->height - 56;
    }
}

void wm_close(uint32_t id) {
    if (id < window_count) {
        windows[id].visible = 0;
    }
}

static void draw_controls(wm_window_t* w) {
    uint32_t right = (uint32_t)(w->x + (int32_t)w->width - 8);
    gfx_draw_rect(g_ctx, right - 54, (uint32_t)w->y + 6, 12, 12, 0x00F5C542);
    gfx_draw_rect(g_ctx, right - 36, (uint32_t)w->y + 6, 12, 12, 0x0034AADC);
    gfx_draw_rect(g_ctx, right - 18, (uint32_t)w->y + 6, 12, 12, 0x00E64A4A);
}

void wm_draw(void) {
    for (uint32_t i = 0; i < window_count; ++i) {
        wm_window_t* w = &windows[i];
        if (!w->visible || w->minimized) {
            continue;
        }

        gfx_draw_rect(g_ctx, w->x, w->y, w->width, w->height, 0x00EDEDED);
        gfx_draw_rect(g_ctx, w->x, w->y, w->width, 32, 0x001D1F23);
        gfx_draw_frame(g_ctx, w->x, w->y, w->width, w->height, 0x00B2B6C2);
        gfx_draw_text(g_ctx, w->x + 10, w->y + 8, w->title, 0x00FFFFFF);
        draw_controls(w);
    }

    taskbar_draw();
    start_menu_draw();
}
