#include "print_eq.h"

void PrintEq(struct square_equation eq_print){
    printf("\nTest: a = %lg, b = %lg, c = %lg.\n", eq_print.a, eq_print.b, eq_print.c);
    if (eq_print.n_roots == 0){
        printf("This equation has no roots.\n\n");
    }
    else if (eq_print.n_roots == 1){
        printf("This equation has 1 root: \nx = %lg\n\n", eq_print.x1);
    }
    else if (eq_print.n_roots == 2){
        printf("This equation has 2 root: \nx1 = %lg, x2 = %lg\n\n", eq_print.x1, eq_print.x2);
    }
}

void PrintEqFile(struct square_equation eq_print){
    FILE *file = fopen("file_for_writing.txt", "a");
    if (file == NULL) {
        printf("I can't open file_for_writing.txt\n");
        fclose(file);
        return;
    }
    
    fprintf(file, "Test: a = %lg, b = %lg, c = %lg, n_roots = %d, x1 = %lg, x2 = %lg\n\n",
         eq_print.a, eq_print.b, eq_print.c, eq_print.n_roots, eq_print.x1, eq_print.x2);

    fclose(file);
}