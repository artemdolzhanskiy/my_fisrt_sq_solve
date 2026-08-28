#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "solve_eq.h"

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

/*!
    \brief Autotests

    This function testing program on correct data.

*/
void RunTests();

#endif