#ifndef INFINITYOS_SCHEDULER_H
#define INFINITYOS_SCHEDULER_H

#include <stdint.h>

#define MAX_TASKS 16

typedef void (*task_entry_t)(void);

typedef struct {
    uint32_t id;
    const char* name;
    task_entry_t entry;
    uint8_t active;
} task_t;

void scheduler_init(void);
int scheduler_add_task(const char* name, task_entry_t entry);
void scheduler_tick(void);

#endif
