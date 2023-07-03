#include "mathlib.h"

#include <math.h>
#include <stdio.h>
int madhava_terms = 0;
double pi_madhava(void) {
  double eval = 0.0;
  double sum = 0.0;
  double step = 0.0;
  double top = 1.0;    // numerator of the equation
  double bottom = 0.0; // denominator of the equation
  do {
    bottom = (2.0 * madhava_terms) + 1.0;
    step = 1.0 / (top * bottom);
    sum += step;
    eval = sum * sqrt_newton(12, true);
    top *= -3.0;
    madhava_terms++;
  } while (absolute(step) > EPSILON && madhava_terms < 1000);
  printf("pi_madhava() = %15.16f, ", eval);
  printf("M_PI = %15.16f, ", M_PI);
  printf("diff = %15.16f\n", absolute(eval - M_PI));
  return sum;
}

int pi_madhava_terms(void) { return madhava_terms; }
