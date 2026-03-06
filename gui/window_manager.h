#ifndef INFINITYOS_WINDOW_MANAGER_H
#define INFINITYOS_WINDOW_MANAGER_H

#include <stdint.h>
#include "../kernel/include/graphics.h"

#define WM_MAX_WINDOWS 16

typedef struct {
    uint32_t id;
    const char* title;
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
    uint8_t minimized;
    uint8_t maximized;
    uint8_t visible;
} wm_window_t;

void wm_init(gfx_context_t* ctx);
gfx_context_t* wm_context(void);
uint32_t wm_create_window(const char* title, int32_t x, int32_t y, uint32_t w, uint32_t h);
void wm_minimize(uint32_t id);
void wm_maximize(uint32_t id);
void wm_close(uint32_t id);
void wm_draw(void);

#endif
