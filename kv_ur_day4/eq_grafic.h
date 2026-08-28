#ifndef EQ_GRAFIC_H
#define EQ_GRAFIC_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "input_eq.h"

/*!
    \brief Plot

    This function draw plot of square equation in file
*/
void EqGrafic(struct square_equation eq);

/*!
    \brief Compare with eps

    This function help draw plot
    \return true or false
*/
bool EqualityEpsGraf(double ob_1, double ob_2);

#endif