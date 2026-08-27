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

// TODO вынести отдельно вывод в файл и график

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Enter      ./a.exe -help      for info.\n\n");
        exit(0);
    }


    if (!strcmp(argv[1], "-help")){
        printf( "-help - get information about this program\n"
                "-enter_test - user can enter test\n"
                "-auto_test - program start autotesting\n"
                "-test_from_file - program start testing on data from file file_with_data.txt\n"
                "-training - program can help you training solve square equation\n"
                "-write_test_to_file - program write a b c(from user), n_roots, x1, x2(from program) in file_for_writing.txt\n"
                "-draw_grafic - program draw a grafic on results of test from user to file_for_grafic.txt\n");
    }//--------------------------------------------------------------------------------------------------------
    else if (!strcmp(argv[1], "-enter_test")){
        while (true){
            printf("Please enter data\n");

            struct square_equation eq = InputEq();

            eq = SolveEq(eq);

            PrintEq(eq);


            printf("Do you want to write results of last test to file_for_writing.txt?\n");
            printf("Enter 1 if YES or 0 if NO:  ");

            int choose1 = 0;
            scanf("%d", &choose1);
            printf("As you command, my lord.\n\n");
            if (choose1){
                PrintEqFile(eq);
            }

            printf("Do you want to draw a grafic on results of last test to file_for_grafic.txt?\n");
            printf("Enter 1 if YES or 0 if NO:  ");
            scanf("%d", &choose1);
            printf("As you command, my lord.\n\n");
            if (choose1){
                EqGrafic(eq);
            }


            printf("Do you want to try again?\n");
            printf("Enter 1 or 0:  ");
            scanf("%d", &choose1);
            printf("As you command, my lord.\n\n");
            if (choose1 != 1){
                exit(0);
            }

        }
    }//--------------------------------------------------------------------------------------------------------
    else if (!strcmp(argv[1], "-auto_test")){
        printf("OK! Starting autotesting\n\n");

        RunTests();
    }//--------------------------------------------------------------------------------------------------------
    else if (argc > 1 && !strcmp(argv[1], "-test_from_file")){
        printf("\nOK! Starting testing on data from file file_with_data.txt\n");

        int k_test_before = 0;
        while (true){
            struct square_equation eq = InputEqFile(k_test_before);
            
            if (isnan(eq.a) && isnan(eq.b) && isnan(eq.c))
                break;

            k_test_before += 1;

            if (isnan(eq.a) || isnan(eq.b) || isnan(eq.c)){
                printf("I can't reed %d test\n\n", k_test_before);
                break;
            }

            eq = SolveEq(eq);

            if (isnan(eq.a))
                break;
            
            PrintEq(eq);

        }
    }//--------------------------------------------------------------------------------------------------------
    else if (!strcmp(argv[1], "-training")){
        while (true){
            printf("\nOK! You can try solve square equations from file_with_data.txt\n\n");
            printf("At first enter how many roots and when enter them all whith eps = 0.001.\n\n");

            StartTraining();
            
            printf("Tests ran out. Good luck!\n\n");

        }
    }//--------------------------------------------------------------------------------------------------------
    else if (!strcmp(argv[1], "-write_test_to_file")){
        printf("Please enter data\n");
        struct square_equation eq = InputEq();
        eq = SolveEq(eq);

        PrintEqFile(eq);
        printf("Mission completed, my lord\n\n");

    }
    else if (!strcmp(argv[1], "-draw_grafic")){
        printf("Please enter data\n");
        struct square_equation eq = InputEq();
        eq = SolveEq(eq);

        EqGrafic(eq);
        printf("Mission completed, my lord\n\n");

    }
    else {
        printf("Sorry, i don't understand.\n\n");
    }


    return 0;
}