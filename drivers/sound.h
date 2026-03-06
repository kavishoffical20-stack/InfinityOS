#ifndef INFINITYOS_SOUND_H
#define INFINITYOS_SOUND_H

#include <stdint.h>

void sound_init(void);
void sound_beep(uint32_t hz, uint32_t ms);

#endif
