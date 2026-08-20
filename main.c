#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>


void priv(double a, double b, double c);
void poka(double x1, double x2);
void a_0(double a, double b, double c);
void b_0(double a, double b, double c);
void umn_vvod(double *t);

double min_root_kv_ur(double a, double b, double c);
double max_root_kv_ur(double a, double b, double c);
double descriminant(double a, double b, double c);





int main(){
    printf("Hello! This program solve kv_ur. \nEnter input data: \n");
    
    double a = 0, b = 0, c = 0;

    printf("a:  ");
    umn_vvod(&a);

    printf("b:  ");
    umn_vvod(&b);

    printf("c:  ");
    umn_vvod(&c);


    if (a == 0 && b != 0){
        a_0(a, b, c);
        exit(0);
    }else if (a == 0 && b == 0){
        printf("This equation has dohuya roots.\n");
        exit(0);
    }


    priv(a, b, c);

    if (descriminant(a, b, c) < 0){
        exit(0);
    }

    double x1 = 0, x2 = 0;
    x1 = min_root_kv_ur(a, b, c);
    x2 = max_root_kv_ur(a, b, c);

    poka(x1, x2);

    return 0;
}





void priv(double a, double b, double c){
    if (descriminant(a, b, c) == 0)
        printf("This equation has 1 root.\n");
    else if (descriminant(a, b, c) > 0)
        printf("This equation has 2 roots.\n");
    else
        printf("This equation hasn't roots.\n");
}


void a_0(double a, double b, double c){
    printf("equation is liner, because a = 0.\n");
    double res3 = (-c) / b;
    printf("equation has 1 root %lf\n", res3);
}


void poka(double x1, double x2){
    if (x1 == x2){
        printf("root %lf \n", x1);
    }
    else{
        printf("min_root %lf \n", x1);
        printf("max_root %lf \n", x2);
    }
}


void umn_vvod(double *t){
    char str[100], *end;;
    gets(str);
    for (int i = 0; str[i] != NULL; ++i){
        if (!isdigit(str[i]) && str[i] != '-'){
            printf("incorrect data\n");
            exit(0);
        }
    }
    *t = atof(str);
}


double descriminant(double a, double b, double c){
    double Descr = (b * b - 4 * a * c);
    return Descr;
}


double min_root_kv_ur(double a, double b, double c){
    double D = descriminant(a, b, c);
    
    double res1 = (-b - sqrt(D)) / (2 * a);
    return res1;
}


double max_root_kv_ur(double a, double b, double c){
    double D = descriminant(a, b, c);

    double res2 = (-b + sqrt(D)) / (2 * a);
    return res2;
}
