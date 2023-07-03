#include "mathlib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aebmrvnsh"

// this is basically copied from the getopt example in the asgn2.pdf.
int main(int argc, char **argv) {
  // static bool print_stats = false;
  int opt = 0;

  while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
    switch (opt) {
    case 'a':
      e();
      pi_bbp();
      pi_madhava();
      pi_euler();
      pi_viete();
      for (double i = 0.0; i < 10.0; i += .1) {
        sqrt_newton(i, false);
      }
      break;
    case 'e':
      e();
      break;
    case 'b':
      pi_bbp();
      break;
    case 'm':
      pi_madhava();
      break;
    case 'r':
      pi_euler();
      break;
    case 'v':
      pi_viete();
      break;
    case 'n':
      for (double i = 0.0; i <= 10.0; i += .1) {
        sqrt_newton(i, false);
      }
      break;
    case 's':
      break;
    case 'h':
      break;
    default:
      printf("error? this message shouldn't pop up even if there is an "
             "incorrect input");
    }
  }
  return 0;
}
