#ifndef SOLVE_EQ_H
#define SOLVE_EQ_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "input_eq.h"


/*!
    \brief Solve

    This function  solve square equation. Caltulating discriminant and roots.

    \return struct square_equation with roots of square equation
*/
struct square_equation SolveEq(struct square_equation eq);

/*!
    \brief Compare with eps

    This function compare two float numbers

    \return true or false
*/
bool EqualityEps(double ob_1, double ob_2);

#endif