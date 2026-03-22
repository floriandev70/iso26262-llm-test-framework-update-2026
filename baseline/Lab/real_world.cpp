#include "includes/real_world.h"

bool check_abort(bool off_course, bool abort_commanded, bool valid_abort_command) {
  bool result = false;
  if (off_course || (abort_commanded && valid_abort_command)) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

int autom_MCU_state_machine(int requested_state) {
  if (requested_state == CURRENT_STATE) {
    return g_current_state;
  }

  int new_state = g_current_state;

  switch (g_current_state) {
    case OFF:
      if (requested_state == RUN) {
        new_state = STARTUP;
      } else {
        return -1;
      }
      break;
    case RUN:
      if (requested_state == SLEEP) {
        new_state = GO_SLEEP;
      } else if (requested_state == OFF) {
        new_state = SHUTDOWN;
      } else {
        return -1;
      }
      break;
    case SLEEP:
      if (requested_state == RUN) {
        new_state = WAKEUP;
      } else {
        return -1;
      }
      break;
    default:
      return -1;
  }

  switch (new_state) {
    case STARTUP:
      g_current_state = RUN;
      break;
    case SHUTDOWN:
      g_current_state = OFF;
      break;
    case WAKEUP:
      g_current_state = RUN;
      break;
    case GO_SLEEP:
      g_current_state = SLEEP;
      break;
    default:
      break;
  }

  return g_current_state;
}
