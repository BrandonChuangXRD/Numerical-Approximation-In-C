#include "mathlib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aebmrvnsh"

int main(int argc, char **argv) {
  int opt = 0;
  bool print_stats = false;
  bool run_e = false;
  bool run_bbp = false;
  bool run_madhava = false;
  bool run_euler = false;
  bool run_viete = false;
  bool run_newton = false;
  bool print_help = false;
  while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
    switch (opt) {
    case 'h':
      print_help = true;
      break;
    case 's':
      print_stats = true;
      break;
    case 'a':
      run_e = true;
      run_bbp = true;
      run_madhava = true;
      run_euler = true;
      run_viete = true;
      run_newton = true;
      break;
    case 'e':
      run_e = true;
      break;
    case 'b':
      run_bbp = true;
      break;
    case 'm':
      run_madhava = true;
      break;
    case 'r':
      run_euler = true;
      break;
    case 'v':
      run_viete = true;
      break;
    case 'n':
      run_newton = true;
      break;
    default:
      printf("ERROR: This message should never be printed.");
    }
  }
  // execution part
  if (print_help) {
    printf(
        "usage: ./mathlib-test [-h] [-s] [-a] [-e] [-b] [-m] [-r] [-v] [-n]\n");
    printf("options:\n");
    printf("   -h: show this help message and exit\n");
    printf("   -s: show number of terms/factors/iterations for each algorithm "
           "executed\n");
    printf("   -a: execute all algorithms\n");
    printf("   -e: execute Jacob Bernoulli's taylor series approximation "
           "algorithm for e\n");
    printf(
        "   -b: execute the Bailey-Borwein-Plouffe formula algorithm for pi\n");
    printf(
        "   -m: execute the Madhava Series approximation algorithm for pi\n");
    printf(
        "   -r: execute the eurler identity approximation algorithm for pi\n");
    printf("   -v: execute the Viete's formula algorithm for pi\n");
    printf("   -n: execute the Newton-Rhapson's approxmation algorithm for "
           "square roots for every 1/10th number from 0-10 inclusive\n");
    return 0;
  }
  if (run_e) {
    e();
    if (print_stats) {
      printf("number of terms: %d\n", e_terms());
    }
  }
  if (run_bbp) {
    pi_bbp();
    if (print_stats) {
      printf("number of terms: %d\n", pi_bbp_terms());
    }
  }
  if (run_madhava) {
    pi_madhava();
    if (print_stats) {
      printf("number of terms: %d\n", pi_madhava_terms());
    }
  }
  if (run_euler) {
    pi_euler();
    if (print_stats) {
      printf("number of terms: %d\n", pi_euler_terms());
    }
  }
  if (run_viete) {
    pi_viete();
    if (print_stats) {
      printf("number of factors: %d\n", pi_viete_factors());
    }
  }
  if (run_newton) {
    for (double i = 0.0; i <= 10.0; i += .1) {
      sqrt_newton(i, false);
      if (print_stats) {
        printf("number of iterations: %d\n", sqrt_newton_iters());
      }
    }
  }
  return 0;
}
