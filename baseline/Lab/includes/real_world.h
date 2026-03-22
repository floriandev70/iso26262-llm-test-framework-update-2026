#ifndef REAL_WORLD_H
#define REAL_WORLD_H

#include <stdbool.h>

#define CURRENT_STATE 0
#define ON 1
#define STARTUP 2
#define RUN 3
#define GO_SLEEP 4
#define SLEEP 5
#define WAKEUP 6
#define SHUTDOWN 7
#define OFF 8

inline int g_current_state = OFF;

bool check_abort(bool off_course, bool abort_commanded, bool valid_abort_command);
int autom_MCU_state_machine(int requested_state);

#endif
