#ifndef INFINITYOS_DISPLAY_H
#define INFINITYOS_DISPLAY_H

#include <stdint.h>
#include "../kernel/include/graphics.h"

void display_init(gfx_context_t* ctx);
void display_present(gfx_context_t* ctx);

#endif
