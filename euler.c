#include "mathlib.h"

#include <math.h>
#include <stdio.h>

long long int euler_terms = 1;
double pi_euler(void) {
  long double eval = 0.0;
  long double previous = 0.0;
  double sum = 0.0;
  double temp = 1.0;
  do {
    previous = eval;
    temp = 1.0 / (euler_terms * euler_terms);
    sum += temp;
    eval = sqrt_newton(6 * sum, true);
    euler_terms++;
  } while (absolute(eval - previous) > EPSILON);
  eval = sqrt_newton(6.0 * sum, true);
  printf("euler() = %15.16Lf, ", eval);
  printf("M_PI = %15.16lf, ", M_PI);
  printf("diff = %15.16lf\n", absolute(eval - M_PI));
  return eval;
}

int pi_euler_terms(void) {
  return euler_terms - 1; // I dont have time for clean code
}
