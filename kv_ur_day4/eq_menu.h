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

void Eq_Help();
void Eq_Enter_Test();
void Eq_Auto_Test();
void Eq_Test_From_File();
void Eq_Training();
void Eq_Write_Test_To_File();
void Eq_Draw_Grafic();

#endif