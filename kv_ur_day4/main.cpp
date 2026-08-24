#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "print_eq.h"

// char* a, char a[] 

// TODO argc *argv
int main(){
    
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
            printf("As you command, my lord.\n");
            if (choose){
                PrintEqFile(eq);
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

    return 0;
}