#ifndef SOLVE_EQ_H
#define SOLVE_EQ_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "input_eq.h"

bool EqualityEps(double ob_1, double ob_2);
struct square_equation SolveEq(struct square_equation eq);

#endif