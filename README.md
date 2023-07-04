# Numerical Approximation Algorithms in C
This is an assignment I did in the fall of 2021. It was intended to enforce proper useage of for loops (as well as ease students into coding with C) by having us implement different numerical approximation algorithms, with the user being able to define the number of iterations for each method using a seperate testing program. The inclded algorithms are as follows:

- Jacob Bernoulli's taylor series approximation for e
- Bailey-Borwein-Plouffe Forumla for pi
- Euler's identity for pi
- The Madhava Series for pi
- Viete's formula for pi
- Newton-Raphson method for square roots

# Installation (make commands)
use the included make file and run make to make the executable. The options are as follows:

| flag | description |
| --------- | -------|
| all | create all files |
| mathlib-test | create mathlib-test (identical to "all" or no flag) |
| tidy | remove object (.o) files |
| clean | remove object (.o) and executable binary files |
| format | formats all code using clang-format |

# Usage

to run, simply write ./mathlib-test in the terminal and include the flags that you want to test:

| flag | description |
| ---- | ---- |
| -a | runs all the approximations |
| -e | runs Jacob Bernoulli's taylor series approximation for e |
| -b | runs the Bailey-Borwein-Plouffe formula for pi |
| -m | runs the Madhava Series approximation for pi |
| -r | runs the eurler identity approximation for pi |
| -v | runs Viete's formula for pi |
| -n | runs Newton-Rhapson's approxmation for square roots for every 1/10th number from 0-10 inclusive |
| -h | supplies information on how to use the mathlib-test binary |
| -s | prints the amount of iterations/terms/factors for each approximation that is run |

# ERRORS:
there are none that I am aware of.