#include "mathlib.h"

#include <math.h>
#include <stdio.h>
int viete_factors = 1;
double pi_viete(void) {

  double product = 1.0;
  double previous = 1.0;
  double top_step = 0.0;
  double step = 1.0;
  double eval = 0.0;
  do {
    top_step = sqrt_newton(top_step + 2.0, true);
    step = top_step / 2.0;
    previous = product;
    product *= step;
    viete_factors++;
  } while (absolute(product - previous) > EPSILON);
  eval = 2 / product;
  printf("pi_viete() = %15.16f, ", eval);
  printf("M_PI = %15.16f, ", M_PI);
  printf("diff = %15.16f\n", absolute(M_PI - eval));
  return eval;
}

int pi_viete_factors(void) { return viete_factors; }
