#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

static int newton_iters = 0;
// basically copied from asgn2 paper and translated to c: credit Professor
// (Darrell) Long
double sqrt_newton(double x, bool silent) {
  newton_iters = 0;
  long double z = 0.0;
  long double y = 1.0;
  while (absolute(y - z) > EPSILON) {
    z = y;
    y = 0.5 * (z + x / z);
    newton_iters++;
  }
  if (!silent) {
    printf("sqrt_newton(%f) = %16.15Lf, ", x, y);
    printf("sqrt(%f) = %16.15lf, ", x, sqrt(x));
    printf("diff = %16.15lf\n", absolute(y - sqrt(x)));
  }
  return y;
}

int sqrt_newton_iters(void) { return newton_iters; }
