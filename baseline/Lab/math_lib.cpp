#include "includes/math_lib.h"

int add(int a, int b) {
  if (a < 0 || a > 1000 || b < 0 || b > 1000) {
    return -1;
  }
  if (a > 1500 - b) {
    return -1;
  }
  return a + b;
}

int subtract(int a, int b) {
  if ((a < 0) || (b < 0) || (a > 1000) || (b > 1000)) {
    return -1;
  }
  if (a < b) {
    return -1;
  }
  return a - b;
}

int multiply(int a, int b) {
  if (a < 0 || a > 1000 || b < 0 || b > 1000) {
    return -1;
  }
  if (b > 0 && a > 1500 / b) {
    return -1;
  }
  return a * b;
}

int divide(int a, int b) {
  if (a < 0 || a > 1000 || b <= 0 || b > 1000) {
    return -1;
  }
  return a / b;
}

int factorial(int n) {
  if (n < 0 || n > 1000) {
    return -1;
  }
  int fact = 1;
  for (int i = 2; i <= n; ++i) {
    if (fact > 1500 / i) {
      return -1;
    }
    fact *= i;
  }
  return fact;
}

int fibonacci(int n) {
  if (n < 0 || n > 1000) {
    return -1;
  }
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  int prev = 0;
  int next = 1;
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result = prev + next;
    if (result > 1500 || result < 0) {
      return -1;
    }
    prev = next;
    next = result;
  }
  return result;
}

int prime_number(int n) {
  if ((n < 0) || (n > 1000)) {
    return -1;
  }
  if (n <= 1) {
    return 0;
  }
  if ((n != 2) && (n % 2 == 0)) {
    return 0;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int add_ref(int a, int b) {
  if (a < 0) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  if (a > 1000) {
    return -1;
  }
  if (b > 1000) {
    return -1;
  }
  if (a + b > 1500) {
    return -1;
  }
  return a + b;
}

int subtract_ref(int a, int b) {
  if (a < 0) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  if (a > 1000) {
    return -1;
  }
  if (b > 1000) {
    return -1;
  }
  if (a < b) {
    return -1;
  }
  return a - b;
}

int multiply_ref(int a, int b) {
  if (a < 0) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  if (a > 1000) {
    return -1;
  }
  if (b > 1000) {
    return -1;
  }
  if (b > 0) {
    if (a > 1500 / b) {
      return -1;
    }
  }
  return a * b;
}

int divide_ref(int a, int b) {
  if (a < 0) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  if (a > 1000) {
    return -1;
  }
  if (b > 1000) {
    return -1;
  }
  if (b == 0) {
    return -1;
  }
  return a / b;
}

int prime_number_ref(int n) {
  if (n < 0) {
    return -1;
  }
  if (n > 1000) {
    return -1;
  }
  if (n <= 1) {
    return 0;
  }
  if (n != 2) {
    if (n % 2 == 0) {
      return 0;
    }
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int fibonacci_ref(int n) {
  if (n < 0 || n > 1000) {
    return -1;
  }
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  int prev = 0;
  int next = 1;
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result = prev + next;
    if (result > 1500) {
      return -1;
    }
    prev = next;
    next = result;
  }
  return result;
}

float myFunc(void) {
  int x = 3;
  float f = static_cast<float>(x);
  return f;
}

int16_t Temp_Calc_Pres_Wacol_Temp_48V(struct dcdc_ntc_temp_def const *ntc_temp) {
  float tmp_result = 0.0f;
  float I_KL30_10mA = static_cast<float>(SP_Get_I_Kl30());
  float U_KL30_1mV = static_cast<float>(SP_Get_U_Kl30());
  float abs_I_KL30_10mA = static_cast<float>(UTIL_ABS(I_KL30_10mA));
  float abs_U_KL30 = static_cast<float>(UTIL_ABS(U_KL30_1mV));

  tmp_result = I_KL30_10mA / MILLI * 10.0f * 0.0037f
             + abs_I_KL30_10mA / MILLI * 10.0f * -0.0031f * abs_U_KL30 / MILLI * 0.05f;

  tmp_result += ntc_temp->temp_ntc1 * 1.053f
              + ntc_temp->temp_ntc2 * -0.4578f
              + ntc_temp->temp_ntc3 * -0.6286f
              + ntc_temp->temp_ntc4 * 0.2951f
              + ntc_temp->temp_ntc4 * 1.8444f
              + ntc_temp->temp_ntc4 * -2.0185f
              + ntc_temp->temp_ntc4 * 0.9187f;

  tmp_result += -2.573f;
  return static_cast<int16_t>(tmp_result * 10.0f);
}
