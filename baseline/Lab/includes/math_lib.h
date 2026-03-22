#ifndef MATH_LIB_H
#define MATH_LIB_H

#include <cstdint>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int factorial(int n);
int fibonacci(int n);
int prime_number(int n);
int add_ref(int a, int b);
int subtract_ref(int a, int b);
int multiply_ref(int a, int b);
int divide_ref(int a, int b);
int prime_number_ref(int n);
int fibonacci_ref(int n);
float myFunc(void);

struct dcdc_ntc_temp_def {
  float temp_ntc1;
  float temp_ntc2;
  float temp_ntc3;
  float temp_ntc4;
  float temp_ntc5;
  float temp_ntc6;
  float temp_ntc7;
};

#ifndef UTIL_ABS
#define UTIL_ABS(x) ((x) < 0 ? -(x) : (x))
#endif

#ifndef MILLI
#define MILLI 1000.0f
#endif

static inline int SP_Get_I_Kl30(void) { return 0; }
static inline int SP_Get_U_Kl30(void) { return 0; }

int16_t Temp_Calc_Pres_Wacol_Temp_48V(struct dcdc_ntc_temp_def const *ntc_temp);

#endif
