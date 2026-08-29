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
    
    \param [in] eq struct square_equation with data about square equation 

    \details This function draw plot of square equation in file
*/
void EqGrafic(struct square_equation eq);

/*!
    \brief Compare with eps

    \param [in] ob_1, ob_2two float numbers

    \details This function help draw plot
    \return true or false
*/
bool EqualityEpsGraf(double ob_1, double ob_2);

#endif
