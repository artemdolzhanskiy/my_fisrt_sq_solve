#ifndef INPUT_EQ_H
#define INPUT_EQ_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>



/*!
    \brief Struct for storage square equation

    This struct storag:
    a,b,c - coefficients of square equation
    n_roots - how many roots square equation has
    x1, x2 - square equation's roots 
 */
struct square_equation{
    double a;
    double b;
    double c;
    int n_roots;
    double x1;
    double x2;
};


/*!
    \brief Function for input coefficients of square equation

    \param [out] eq struct square_equation with data about square equation

    \return struct square_equation with data about square equation
*/
void InputEq(struct square_equation *eq);

/*!
    \brief Helping function for InputEq
    
    \param [in] coef (pointer) of square   

    This function input one float number and check him

    \return true if OK or false
*/
bool input_coef(double *coef);

/*!
    \brief Helping function for input_coef

    This function check number

    \return true if OK or false
*/
bool ClearInput_If_Needed();


/*!
    \brief Function for input coefficients of square equation from file

    \param [in] k_test_before how many tests need to skip in file

    \param [out] eq struct square_equation with data about square equation from file

    \return struct square_equation with data about square equation from file
*/
struct square_equation InputEqFile(int k_test_before);

#endif