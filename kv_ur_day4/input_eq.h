#ifndef INPUT_EQ_H
#define INPUT_EQ_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

struct square_equation{
    double a;
    double b;
    double c;
    int n_roots;
    double x1;
    double x2;
};

struct square_equation InputEq();

bool ClearInput_If_Needed();

struct square_equation InputEqFile(int k_test_before);

#endif