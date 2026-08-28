#ifndef EQ_MENU_H
#define EQ_MENU_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "user_training.h"
#include "input_eq.h"
#include "print_eq.h"
#include "solve_eq.h"
#include "tests.h"
#include "eq_grafic.h"

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define BLUE    "\033[34m"
#define LIGHT_BLUE "\033[36m"
#define RESET   "\033[0m"

/*!
    \brief Info

    This function print info about program
*/
void Eq_Help();

/*!
    \brief Test from keyboard

    This scenario for tests from keyboard
*/
void Eq_Enter_Test();

/*!
    \brief Autotests

    This scenario for tests from program
*/
void Eq_Auto_Test();

/*!
    \brief Tests from file

    This scenario for tests from file
*/
void Eq_Test_From_File();

/*!
    \brief Training

    This scenario for training user in solve square equation
*/
void Eq_Training();

/*!
    \brief Write test to file

    This scenario write tests to file
*/
void Eq_Write_Test_To_File();

/*!
    \brief Draw plot

    This scenario draw plot in file
*/
void Eq_Draw_Grafic();


#endif