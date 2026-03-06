#include "keyboard.h"

#define KB_QUEUE_SIZE 32

static keyboard_event_t queue[KB_QUEUE_SIZE];
static int head;
static int tail;

static char scancode_to_ascii(uint8_t scancode) {
    static const char map[] = {
        0, 27, '1', '2', '3', '4', '5', '6',
        '7', '8', '9', '0', '-', '=', '\b', '\t',
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
        'o', 'p', '[', ']', '\n', 0, 'a', 's',
        'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
        '\'', '`'
    };
    if (scancode < sizeof(map)) {
        return map[scancode];
    }
    return 0;
}

void keyboard_init(void) {
    head = 0;
    tail = 0;
}

void keyboard_handle_scancode(uint8_t scancode) {
    keyboard_event_t event;
    event.pressed = (scancode & 0x80) == 0;
    event.keycode = scancode & 0x7F;
    event.ascii = event.pressed ? scancode_to_ascii(event.keycode) : 0;

    queue[tail] = event;
    tail = (tail + 1) % KB_QUEUE_SIZE;
    if (tail == head) {
        head = (head + 1) % KB_QUEUE_SIZE;
    }
}

int keyboard_poll(keyboard_event_t* out_event) {
    if (head == tail) {
        return 0;
    }
    *out_event = queue[head];
    head = (head + 1) % KB_QUEUE_SIZE;
    return 1;
}
