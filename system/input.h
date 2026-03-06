#ifndef INFINITYOS_INPUT_H
#define INFINITYOS_INPUT_H

#include "../drivers/keyboard.h"
#include "../drivers/mouse.h"

void input_init(void);
int input_poll_keyboard(keyboard_event_t* event);
void input_get_mouse(mouse_state_t* state);

#endif
