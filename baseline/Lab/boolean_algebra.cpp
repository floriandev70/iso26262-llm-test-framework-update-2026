#include "includes/boolean_algebra.h"

int return_0(void) { return 0; }
int return_1(void) { return 1; }
bool return_a(bool a) { return a; }
bool return_NOT_a(bool a) { return !a; }

bool check_a_OR_b(bool a, bool b) {
  bool check = false;
  if ((a == true) || (b == true)) {
    check = true;
  }
  return check;
}

bool check_a_XOR_b(bool a, bool b) {
  bool check = false;
  if (((a == true) && (b == false)) || ((a == false) && (b == true))) {
    check = true;
  }
  return check;
}

bool check_a_NOR_b(bool a, bool b) {
  bool check = false;
  if ((a == true) || (b == true)) {
    check = true;
  }
  return !check;
}

bool check_a_AND_b(bool a, bool b) {
  bool check = false;
  if ((a == true) && (b == true)) {
    check = true;
  }
  return check;
}

bool check_a_NAND_b(bool a, bool b) {
  bool check = false;
  if ((a == true) && (b == true)) {
    check = true;
  }
  return !check;
}

bool check_a_OR_b_OR_c(bool a, bool b, bool c) {
  bool check = false;
  if ((a == true) || (b == true) || (c == true)) {
    check = true;
  }
  return check;
}

bool check_a_OR_b_AND_c(bool a, bool b, bool c) {
  bool check = false;
  if (((a == true) || (b == true)) && (c == true)) {
    check = true;
  }
  return check;
}

bool check_a_OR__b_AND_c(bool a, bool b, bool c) {
  bool check = false;
  if ((a == true) || ((b == true) && (c == true))) {
    check = true;
  }
  return check;
}

bool check_a_AND_b_AND_c(bool a, bool b, bool c) {
  bool check = false;
  if ((a == true) && (b == true) && (c == true)) {
    check = true;
  }
  return check;
}

bool check_a_AND_b_OR_a_AND_c(bool a, bool b, bool c) {
  bool check = false;
  if (((a == true) && (b == true)) || ((a == true) && (c == true))) {
    check = true;
  }
  return check;
}

bool check_a_AND_b_XOR_a_AND_c(bool a, bool b, bool c) {
  bool check = false;
  bool a_AND_b = false;
  bool a_AND_c = false;
  if ((a == true) && (b == true)) {
    a_AND_b = true;
  }
  if ((a == true) && (c == true)) {
    a_AND_c = true;
  }
  if (((a_AND_b == true) && (a_AND_c == false)) || ((a_AND_b == false) && (a_AND_c == true))) {
    check = true;
  }
  return check;
}

bool check_a_AND_b_XOR_a_AND_NOT_c(bool a, bool b, bool c) {
  bool check = false;
  bool a_AND_b = false;
  bool a_AND_NOT_c = false;
  if ((a == true) && (b == true)) {
    a_AND_b = true;
  }
  if ((a == true) && (c == false)) {
    a_AND_NOT_c = true;
  }
  if (((a_AND_b == true) && (a_AND_NOT_c == false)) || ((a_AND_b == false) && (a_AND_NOT_c == true))) {
    check = true;
  }
  return check;
}

bool check_a_AND_b_XOR_a_AND_NOT_c_OR_d(bool a, bool b, bool c, bool d) {
  bool check = false;
  bool a_AND_b = false;
  bool a_AND_NOT_c_OR_d = false;
  if ((a == true) && (b == true)) {
    a_AND_b = true;
  }
  if ((a == true) && ((c == false) || (d == true))) {
    a_AND_NOT_c_OR_d = true;
  }
  if (((a_AND_b == true) && (a_AND_NOT_c_OR_d == false)) || ((a_AND_b == false) && (a_AND_NOT_c_OR_d == true))) {
    check = true;
  }
  return check;
}
