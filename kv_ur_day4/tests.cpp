#include "tests.h"

#define N_TESTS 19

void RunTests(){
    
    struct square_equation array_tests[N_TESTS] = {
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
    {0.0, 0.0, 4.2, 0, NAN, NAN},
    {1, 0, 0, 1, 0, NAN}// от матвея
    };

    int true_tests = 0;

    int test_i = 0;
    for (test_i = 0; test_i < N_TESTS; ++test_i){
        struct square_equation eq = {
            .a = array_tests[test_i].a,
            .b = array_tests[test_i].b,
            .c = array_tests[test_i].c,
            .n_roots = 0,
            .x1 = NAN,
            .x2 = NAN
        };

        SolveEq(&eq);

        struct square_equation eq_ref = array_tests[test_i]; 

        if (eq_ref.n_roots == eq.n_roots){
            if ( (eq_ref.n_roots == 0) ||
                 (eq_ref.n_roots == 1 && EqualityEps(eq_ref.x1, eq.x1)) ||
                 (eq_ref.n_roots == 2 && EqualityEps(eq_ref.x1, eq.x1) && EqualityEps(eq_ref.x2, eq.x2)) ){
                //printf(GREEN "Test %d OK!\n\n" RESET, test_i + 1);
                true_tests += 1;
                continue;
            }
        }

        printf(RED "Test %d FAIL!\n" RESET, test_i + 1);
        printf("EXPECTED: a = %lg, b = %lg, c = %lg, n_roots = %d, x1 = %lg, x2 = %lg\n", eq_ref.a, eq_ref.b, eq_ref.c,
                            eq_ref.n_roots, eq_ref.x1, eq_ref.x2);

        printf("SOLVED:   a = %lg, b = %lg, c = %lg, n_roots = %d, x1 = %lg, x2 = %lg\n\n", eq.a, eq.b, eq.c,
                            eq.n_roots, eq.x1, eq.x2);
    }

    printf(GREEN "%d/%d tests completed \n\n" RESET, true_tests, N_TESTS);

}


