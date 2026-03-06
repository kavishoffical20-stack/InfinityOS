#include "input.h"

void input_init(void) {
    keyboard_init();
    mouse_init();
}

int input_poll_keyboard(keyboard_event_t* event) {
    return keyboard_poll(event);
}

void input_get_mouse(mouse_state_t* state) {
    mouse_get_state(state);
}
