#ifndef PRINT_EQ_H
#define PRINT_EQ_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "input_eq.h"

#define BLUE    "\033[34m"
#define RESET   "\033[0m"

/*!
    \brief Results of test

    This function print results of test in terminal

*/
void PrintEq(struct square_equation eq_print);


/*!
    \brief Results of test

    This function print results of test in file
*/
void PrintEqFile(struct square_equation eq_print);

#endif