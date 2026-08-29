#include "user_training.h"


void StartTraining(){
    FILE *file = fopen("file_with_data.txt", "r");
    if (file == NULL) {
        printf("I can't open file_with_data.txt.\n");
        fclose(file);
        exit(0);
    }


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

        SolveEq(&eq);

        if (isnan(eq.a))
            break;


        double user_x1 = NAN, user_x2 = NAN;
        int user_n_roots = 0;

        while (true){
            printf("Test: a = %lg, b = %lg, c = %lg\n",eq.a, eq.b, eq.c);

            printf("Enter how many roots:  ");
            scanf("%d", &user_n_roots);
            
            if (ClearInput_If_Needed()){
                printf("Incorrect format! Try again!\n\n");
                continue;
            }
            
            if (user_n_roots != eq.n_roots){
                printf("Incorrect how many roots! Try again!\n\n");
                continue;
            }

            if (user_n_roots == 0 && eq.n_roots == 0){
                printf("Correct! Good job!\n\n");
                break;
            }
            else if (user_n_roots == 1){
                printf("Enter x1:  ");
                scanf("%lg", &user_x1);
            
                if (ClearInput_If_Needed()){
                    printf("Incorrect format! Try again!\n\n");
                    continue;
                }

                if (EqualityEps(user_x1, eq.x1)){
                    printf("Correct! Good job!\n\n");
                    break;
                }
            }
            else if (user_n_roots == 2){
                printf("Enter x1:  ");
                scanf("%lg", &user_x1);
            
                if (ClearInput_If_Needed()){
                    printf("Incorrect format! Try again!\n\n");
                    continue;
                }

                printf("Enter x2:  ");
                scanf("%lg", &user_x2);
            
                if (ClearInput_If_Needed()){
                    printf("Incorrect format! Try again!\n\n");
                    continue;
                }

                if ((EqualityEps(user_x1, eq.x1) && EqualityEps(user_x2, eq.x2)) || (EqualityEps(user_x1, eq.x2) && EqualityEps(user_x2, eq.x1))) {
                    printf("Correct! Good job!\n\n");
                    break;
                }
            } 
            printf("Incorrect! Try again!\n\n");
        }
    }

    fclose(file);
}