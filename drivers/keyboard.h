#ifndef INFINITYOS_KEYBOARD_H
#define INFINITYOS_KEYBOARD_H

#include <stdint.h>

typedef struct {
    uint8_t keycode;
    char ascii;
    uint8_t pressed;
} keyboard_event_t;

void keyboard_init(void);
void keyboard_handle_scancode(uint8_t scancode);
int keyboard_poll(keyboard_event_t* out_event);

#endif
