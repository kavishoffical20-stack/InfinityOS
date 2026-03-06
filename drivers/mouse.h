#ifndef INFINITYOS_MOUSE_H
#define INFINITYOS_MOUSE_H

#include <stdint.h>

typedef struct {
    int32_t x;
    int32_t y;
    uint8_t left;
    uint8_t right;
    uint8_t middle;
} mouse_state_t;

void mouse_init(void);
void mouse_update(int32_t dx, int32_t dy, uint8_t buttons);
void mouse_get_state(mouse_state_t* out_state);

#endif
