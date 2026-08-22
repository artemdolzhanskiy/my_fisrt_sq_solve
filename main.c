#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

#define EPS = 0.001;

struct square_equation{
    double A;
    double B;
    double C;
    int N_ROOTS;
    double X1;
    double X2;
};

void run_tests();


struct square_equation solve_eq(struct square_equation eq);




bool equality_eps(double ob_1, double ob_2);





int main(){
    printf("ok\n");

    run_tests();

    return 0;

}


void run_tests(){
    struct square_equation array_tests[18] = {
    {1, -5, 6, 2, 2, 3},
    {1, -4, 4, 1, 2, NAN},
    {1, 0, -4, 2, -2, 2},
    {1, 4, 0, 2, -4, 0},
    {1, 0, 0, 1, 0, NAN},
    {1, 2, 5, 0, NAN, NAN},
    {0, 2, -4, 1, 2, NAN},
    {0, 0, 5, 0, NAN, NAN},
    {1, -10000000, 1, 2, 1e-7, 9999999.9999999},
    {1.5, -3.2, 1.1, 2, 0.4307, 1.7026},
    {0.5, -2.0, 2.0, 1, 2, NAN},
    {2.5, 5.0, 2.5, 1, -1, NAN},
    {-1.2, 4.5, -3.1, 2, 0.9094, 2.8406},
    {3.14, 0.0, -2.71, 2, -0.929, 0.929},
    {0.0, 2.5, -5.0, 1, 2, NAN},
    {1.25, -5.5, 0.0, 2, 0, 4.4},
    {-0.5, 0.0, -1.5, 0, NAN, NAN},
    {0.0, 0.0, 4.2, 0, NAN, NAN}
    };

    for (int test_i = 0; test_i < 18; ++test_i){
        struct square_equation eq;
        eq.A = array_tests[test_i].A, eq.B = array_tests[test_i].B, eq.C = array_tests[test_i].C;
        eq.N_ROOTS = 0; eq.X1 = NAN, eq.X2 = NAN;

        eq = solve_eq(eq);

        if (array_tests[test_i].N_ROOTS == eq.N_ROOTS){
            if ( (array_tests[test_i].N_ROOTS == 0) ||
                 (array_tests[test_i].N_ROOTS == 1 && equality_eps(array_tests[test_i].X1, eq.X1)) ||
                    (array_tests[test_i].N_ROOTS == 2 && equality_eps(array_tests[test_i].X1, eq.X1) && equality_eps(array_tests[test_i].X2, eq.X2)) ){
                printf(GREEN "Test %d OK!\n\n" RESET, test_i + 1);
                continue;
            }
        }

        printf(RED "Test %d FAIL!\n" RESET, test_i + 1);
        printf("EXPECTED: a = %lg, b = %lg, c = %lg, n_roots = %d, x1 = %lg, x2 = %lg\n", array_tests[test_i].A, array_tests[test_i].B, array_tests[test_i].C,
                            array_tests[test_i].N_ROOTS, array_tests[test_i].X1, array_tests[test_i].X2);

        printf("SOLVED:   a = %lg, b = %lg, c = %lg, n_roots = %d, x1 = %lg, x2 = %lg\n\n", eq.A, eq.B, eq.C,
                            eq.N_ROOTS, eq.X1, eq.X2);
    }
}


bool equality_eps(double ob_1, double ob_2){
    return (fabs(ob_1 - ob_2) <= 0.001);
}


struct square_equation solve_eq(struct square_equation eq){
    double D  = (eq.B * eq.B - 4 * eq.A * eq.C);

    if (eq.A == 0 && eq.B != 0){
        eq.X1 = -eq.C / eq.B;
        D = -1;
    }

    if (D > 0){
        eq.X1 = (-eq.B - sqrt(D)) / (2 * eq.A);
        eq.X2 = (-eq.B + sqrt(D)) / (2 * eq.A);
        double x_min = fmin(eq.X1, eq.X2);
        double x_max = fmax(eq.X1, eq.X2);
        eq.X1 = x_min;
        eq.X2 = x_max;
    }else if (D == 0){
        eq.X1 = (-eq.B) / (2 * eq.A);
    }

    eq.N_ROOTS = (!isnan(eq.X1)) + (!isnan(eq.X2));

    return eq;
}

