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

    \param [in] struct square_equation eq with data about square equation (a, b, c)
    \param [out] struct square_equation eq with results of solve square equation (n_roots, x1, x2)

    \details This function  solve square equation. Caltulating discriminant and roots.  



    \return struct square_equation with roots of square equation
*/
void SolveEq(struct square_equation *eq);

/*!
    \brief Compare with eps

    \param [in] two float numbers

    \details This function compare two float numbers

    \return true or false
*/
bool EqualityEps(double ob_1, double ob_2);

#endif