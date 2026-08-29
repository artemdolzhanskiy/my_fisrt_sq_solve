#include "solve_eq.h"

const double EPS = 0.001;

bool EqualityEps(double ob_1, double ob_2){
    return (fabs(ob_1 - ob_2) <= EPS);
}

void SolveEq(struct square_equation *eq){
    double discr = (eq->b * eq->b - 4 * eq->a * eq->c);

    if (EqualityEps(eq->a, 0) && !EqualityEps(eq->b, 0)){
        eq->x1 = -eq->c / eq->b;
        discr = -1;
    }

    if (discr > 0){
        double sq_d = sqrt(discr);
        eq->x1 = (-eq->b - sq_d) / (2 * eq->a);
        eq->x2 = (-eq->b + sq_d) / (2 * eq->a);
        double x_min = fmin(eq->x1, eq->x2);
        double x_max = fmax(eq->x1, eq->x2);
        eq->x1 = x_min;
        eq->x2 = x_max;
        if (EqualityEps(eq->x1, 0)) eq->x1 = 0;
        if (EqualityEps(eq->x2, 0)) eq->x2 = 0;
    }else if (EqualityEps(discr, 0)){
        eq->x1 = (-eq->b) / (2 * eq->a);
        if (EqualityEps(eq->x1, 0)) eq->x1 = 0;
    }

    eq->n_roots = (!isnan(eq->x1)) + (!isnan(eq->x2));
}