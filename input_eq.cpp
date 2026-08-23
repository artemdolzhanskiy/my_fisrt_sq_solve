#include "input_eq.h"


struct square_equation InputEq(){

    while (true){
        double a = NAN, b = NAN, c = NAN;
        printf("a:  ");
        scanf("%lf", &a);
        if (ClearInput_If_Needed()){
            printf("Incorrect data! Try again!\n");
            continue;
        }

        printf("b:  ");
        scanf("%lf", &b);
        if (ClearInput_If_Needed()){
            printf("Incorrect data! Try again!\n");
            continue;
        }

        printf("c:  ");
        scanf("%lf", &c);
        if (ClearInput_If_Needed()){
            printf("Incorrect data! Try again!\n");
            continue;
        }
        
        struct square_equation eq_input =  {a, b, c, 0, NAN, NAN};
        return eq_input;

    }


}

bool ClearInput_If_Needed(){
    int c = 0;
    bool flag = false;
    while ((c = getchar()) != '\n' || c != EOF){
        if (!isspace(c))
            flag = true;
        if (c == '\n') break;
    }
    return flag;
}




