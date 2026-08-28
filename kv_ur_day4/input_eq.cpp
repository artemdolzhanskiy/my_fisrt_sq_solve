#include "input_eq.h"


struct square_equation InputEq(){

    while (true){
        double a = NAN, b = NAN, c = NAN;
        
        printf("a:  ");
        if (input_coef(&a)){
            printf("Incorrect data! Try again!\n");
            continue;
        }
        
        printf("b:  ");
        if (input_coef(&b)){
            printf("Incorrect data! Try again!\n");
            continue;
        }
        
        printf("c:  ");
        if (input_coef(&c)){
            printf("Incorrect data! Try again!\n");
            continue;
        }

        struct square_equation eq_input =  {a, b, c, 0, NAN, NAN};
        return eq_input;

    }

}

bool input_coef(double *coef){
    scanf("%lf", coef);
    return ClearInput_If_Needed();
    
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

struct square_equation InputEqFile(int k_test_before){
    struct square_equation eq_input = {
            .a = NAN,
            .b = NAN,
            .c = NAN,
            .n_roots = 0,
            .x1 = NAN,
            .x2 = NAN
        };
    
    FILE *file = fopen("file_with_data.txt", "r");
    if (file == NULL) {
        printf("I can't open file_with_data.txt.\n");
        fclose(file);
        return eq_input;
    }

    char str[100] = {};
    for (int i = 0; i < k_test_before; ++i) {
        fgets(str, 100, file);
    }

    fscanf(file, "%lg %lg %lg", &eq_input.a, &eq_input.b, &eq_input.c);

    //fscanf(file, "%lg %lg %lg", &eq_input.a, &eq_input.b, &eq_input.c);
    //printf("%lg %lg %lg", eq_input.a, eq_input.b, eq_input.c);
    fclose(file);
    return eq_input;
}
