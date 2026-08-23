#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "tests.h"

int main(){
    
    printf("Hello!\nThis program solve square equation!\nYou can enter the data yourself or start autotesting.\n");
    printf("Enter: 1 for input yourself, 2 for autotesting or 0 for stop:  ");
    
//TODO: v -> choose
    int v = 0;
    //clear_input();

    while (true){
        scanf("%d", &v);
        //printf("%d", v);
        if (v == 0){
            break;
        }
        else if (v == 1){
            printf("OK! Please enter data\n");

            struct square_equation eq = InputEq();

            eq = SolveEq(eq);

            printf("%lg %lg\n\n", eq.x1, eq.x2);

        }
        else if (v == 2){
            printf("OK! Starting autotesting\n\n");

            RunTests();
        }
    }

    return 0;
}