#include "mathlib.h"

#include <math.h>
#include <stdio.h>
static int bbp_terms = 0;
double pi_bbp(void) {
  int k = 0;
  double eval =
      0.0; // this is supposed to stand for "evaulation", not value of e
  double expo = 1.0;
  double temp = 0.0;
  do {
    temp = 4.0 / (8.0 * k + 1);
    temp -= 2.0 / (8.0 * k + 4);
    temp -= 1.0 / (8.0 * k + 5);
    temp -= 1.0 / (8.0 * k + 6);
    eval += temp / expo;
    k++;
    expo *= 16;
  } while (temp / expo > EPSILON);
  printf("pi_bbp() = %15.16lf, ", eval);
  printf("M_PI = %15.16lf, ", M_PI);
  printf("diff = %15.16lf\n", absolute(eval - M_PI));
  bbp_terms = k;
  return eval;
}

int pi_bbp_terms(void) { return bbp_terms; }
