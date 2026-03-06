#include "include/scheduler.h"

static task_t tasks[MAX_TASKS];
static uint32_t task_count;
static uint32_t current_task;

void scheduler_init(void) {
    task_count = 0;
    current_task = 0;
    for (uint32_t i = 0; i < MAX_TASKS; ++i) {
        tasks[i].active = 0;
    }
}

int scheduler_add_task(const char* name, task_entry_t entry) {
    if (task_count >= MAX_TASKS) {
        return -1;
    }
    tasks[task_count].id = task_count;
    tasks[task_count].name = name;
    tasks[task_count].entry = entry;
    tasks[task_count].active = 1;
    return (int)task_count++;
}

void scheduler_tick(void) {
    if (task_count == 0) {
        return;
    }

    for (uint32_t i = 0; i < task_count; ++i) {
        current_task = (current_task + 1) % task_count;
        if (tasks[current_task].active && tasks[current_task].entry) {
            tasks[current_task].entry();
            break;
        }
    }
}
