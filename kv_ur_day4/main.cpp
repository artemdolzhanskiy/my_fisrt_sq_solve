#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eq_grafic.h"



int main(int argc, char *argv[]){

    /*
    for (int i = 0; i < argc; ++i){
        printf("%s\n",argv[i]);
    }*/
    


    if (argc > 1 && !strcmp(argv[1], "-help")){
        printf( "-help - get information about this program\n"
                "-enter_test - user can enter test\n"
                "-auto_test - program start autotesting\n"
                "-test_from_file - program start testing on data from file file_with_data.txt\n"
                "-training - program can help you training solve square equation\n");
    }
    else if (argc > 1 && !strcmp(argv[1], "-training")){
        /*while (true){
            printf("OK! You can try solve square equations from file_with_data.txt\n");
            printf("For everyone equation enter all roots\n");

            FILE *file = fopen("file_with_data.txt", "r");
            if (file == NULL) {
                printf("I can't open file_with_data.txt.\n");
                fclose(file);
                exit(0);
            }

            fclose(file);

        }*/
    }
    else if (argc > 1 && !strcmp(argv[1], "-enter_test")){
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
    }
    else if (argc > 1 && !strcmp(argv[1], "-auto_test")){
        printf("OK! Starting autotesting\n\n");

        RunTests();
    }
    else if (argc > 1 && !strcmp(argv[1], "-test_from_file")){
        printf("OK! Starting testing on data from file file_with_data.txt\n\n");

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
    }
    else {
        printf("Sorry, i don't understand.\n\n");
    }


    return 0;
}








/*
    printf("Hello!\nThis program solve square equation!\nYou can enter the data yourself or start autotesting.\n\n");
    
    int choose = 0;
    //clear_input();
    while (true){
        printf("Enter: \n1 to input yourself \n2 to autotesting \n3 to start testing on data from file file_with_data.txt \n0 to stop\n: ");

        scanf("%d", &choose);
        printf("\n");
        if (choose == 0){
            break;
        }
        else if (choose == 1){
            printf("OK! Please enter data\n");

            struct square_equation eq = InputEq();

            eq = SolveEq(eq);

            PrintEq(eq);

            printf("Do you want to write results of last test to file_for_writing.txt?\n");
            printf("Enter 1 if YES or 0 if NO:  ");

            int choose1 = 0;
            scanf("%d", &choose1);
            printf("As you command, my lord.\n\n");
            if (choose){
                PrintEqFile(eq);
            }

            printf("Do you want to draw a grafic on results of last test to file_for_grafic.txt?\n");
            printf("Enter 1 if YES or 0 if NO:  ");
            scanf("%d", &choose1);
            printf("As you command, my lord.\n\n");
            if (choose){
                EqGrafic(eq);
            }

        }
        else if (choose == 2){
            printf("OK! Starting autotesting\n\n");

            RunTests();
        }
        else if (choose == 3){
            printf("OK! Starting testing on data from file file_with_data.txt\n\n");

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
        }
    }
*/