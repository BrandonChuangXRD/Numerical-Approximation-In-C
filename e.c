#include "mathlib.h"

#include <math.h>
#include <stdio.h>

static int e_loops = 0;
double e(void) {
  // int k is the K in the equation
  double eval = 1.0;
  double prev_factorial = 1.0;
  do {
    e_loops++;
    prev_factorial *= e_loops;
    eval += 1.0 / prev_factorial;
  } while (1.0 / prev_factorial > EPSILON && e_loops < 1000);
  printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", eval, M_E,
         absolute(eval - M_E));
  return eval;
}

int e_terms(void) { return e_loops; }
