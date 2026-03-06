#include "include/graphics.h"
#include "include/kernel.h"

static inline void put_pixel(gfx_context_t* ctx, uint32_t x, uint32_t y, uint32_t color) {
    if (!ctx || !ctx->framebuffer || x >= ctx->width || y >= ctx->height) {
        return;
    }
    uint32_t stride = ctx->pitch / 4;
    ctx->framebuffer[(y * stride) + x] = color;
}

void gfx_init(gfx_context_t* ctx, uint32_t* fb, uint32_t width, uint32_t height, uint32_t pitch, uint8_t bpp) {
    ctx->framebuffer = fb;
    ctx->width = width;
    ctx->height = height;
    ctx->pitch = pitch;
    ctx->bpp = bpp;
}

void gfx_clear(gfx_context_t* ctx, uint32_t color) {
    if (!ctx || !ctx->framebuffer) return;
    for (uint32_t y = 0; y < ctx->height; ++y) {
        for (uint32_t x = 0; x < ctx->width; ++x) {
            put_pixel(ctx, x, y, color);
        }
    }
}

void gfx_draw_rect(gfx_context_t* ctx, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
    for (uint32_t yi = y; yi < y + h; ++yi) {
        for (uint32_t xi = x; xi < x + w; ++xi) {
            put_pixel(ctx, xi, yi, color);
        }
    }
}

void gfx_draw_frame(gfx_context_t* ctx, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
    gfx_draw_rect(ctx, x, y, w, 2, color);
    gfx_draw_rect(ctx, x, y + h - 2, w, 2, color);
    gfx_draw_rect(ctx, x, y, 2, h, color);
    gfx_draw_rect(ctx, x + w - 2, y, 2, h, color);
}

void gfx_draw_text(gfx_context_t* ctx, uint32_t x, uint32_t y, const char* text, uint32_t color) {
    (void)color;
    while (*text) {
        gfx_draw_rect(ctx, x, y, 6, 10, 0x00222222);
        x += 8;
        text++;
    }
}
