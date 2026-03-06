#ifndef INFINITYOS_GRAPHICS_H
#define INFINITYOS_GRAPHICS_H

#include <stdint.h>

typedef struct {
    uint32_t* framebuffer;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint8_t  bpp;
} gfx_context_t;

void gfx_init(gfx_context_t* ctx, uint32_t* fb, uint32_t width, uint32_t height, uint32_t pitch, uint8_t bpp);
void gfx_clear(gfx_context_t* ctx, uint32_t color);
void gfx_draw_rect(gfx_context_t* ctx, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
void gfx_draw_frame(gfx_context_t* ctx, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
void gfx_draw_text(gfx_context_t* ctx, uint32_t x, uint32_t y, const char* text, uint32_t color);

#endif
