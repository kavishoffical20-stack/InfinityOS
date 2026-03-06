#include "mouse.h"

static mouse_state_t state;

void mouse_init(void) {
    state.x = 512;
    state.y = 384;
    state.left = 0;
    state.right = 0;
    state.middle = 0;
}

void mouse_update(int32_t dx, int32_t dy, uint8_t buttons) {
    state.x += dx;
    state.y += dy;
    state.left = buttons & 0x1;
    state.right = (buttons >> 1) & 0x1;
    state.middle = (buttons >> 2) & 0x1;
}

void mouse_get_state(mouse_state_t* out_state) {
    *out_state = state;
}
