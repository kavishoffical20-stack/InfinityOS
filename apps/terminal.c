#include "../system/filesystem.h"
#include "../drivers/keyboard.h"

static char terminal_buffer[256];

void app_terminal_tick(void) {
    keyboard_event_t event;
    if (keyboard_poll(&event) && event.pressed && event.ascii) {
        for (int i = 0; i < 255; ++i) {
            if (terminal_buffer[i] == '\0') {
                terminal_buffer[i] = event.ascii;
                terminal_buffer[i + 1] = '\0';
                break;
            }
        }
    }
}
