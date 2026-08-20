#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

/*enum type_of_error(){
    NO_ERROR;
    UNCORRECTED_INPUT_VALUE;
    
    //desc < 0
    //a c = 0
};*/

void roots_count(double a, double b, double c);
void print_roots(double x1, double x2);
void a_0(double a, double b, double c);
void umn_vvod(double *t);
void roots_kv_ur(double a, double b, double c, double *X1, double *x2);
void vvod(double *a, double *b, double *c);
void check_a0_b0(double a, double b, double c);

double descriminant(double a, double b, double c);





int main(){
    printf("Hello! This program solve kv_ur. \nEnter input data: \n");
    

    double a = 0, b = 0, c = 0;
    vvod(&a, &b, &c);

    
    check_a0_b0(a, b, c);


    roots_count(a, b, c);


    double x1 = 0, x2 = 0;
    roots_kv_ur(a, b, c, &x1, &x2);


    print_roots(x1, x2);


    return 0;
}



void vvod(double *a, double *b, double *c){
    printf("a:  ");
    umn_vvod(&*a);

    printf("b:  ");
    umn_vvod(&*b);

    printf("c:  ");
    umn_vvod(&*c);
}
void umn_vvod(double *t){
    char str[100] = {};
    gets(str);
    int count_point = 0;
    for (int i = 0; str[i] != NULL; ++i){
        if (str[i] == '.'){
            count_point += 1;
            if (count_point > 1){
                printf("incorrect data\n");
                exit(0);
            }
        }
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.'){
            printf("incorrect data\n");
            exit(0);
        }
    }
    *t = atof(str);
}


void roots_count(double a, double b, double c){
    if (descriminant(a, b, c) == 0){
        printf("This equation has 1 root.\n");
    }else if (descriminant(a, b, c) > 0){
        printf("This equation has 2 roots.\n");
    }else{
        printf("This equation hasn't roots.\n");
        exit(0);
    }
}


void check_a0_b0(double a, double b, double c){
    if (a == 0 && b != 0){
        printf("equation is liner, because a = 0.\n");
        double res3 = (-c) / b;
        printf("equation has 1 root %lf\n", res3);
        exit(0);
    }else if (a == 0 && b == 0){
        printf("This equation has dohuya roots.\n");
        exit(0);
    }
}


void print_roots(double x1, double x2){
    if (x1 == x2){
        printf("root %lf \n", x1);
    }
    else{
        printf("min_root %lf \n", x1);
        printf("max_root %lf \n", x2);
    }
}


double descriminant(double a, double b, double c){
    double Descr = (b * b - 4 * a * c);
    return Descr;
}


void roots_kv_ur(double a, double b, double c, double *x1, double *x2){
    double D = descriminant(a, b, c);
    
    *x1 = (-b - sqrt(D)) / (2 * a);
    *x2 = (-b + sqrt(D)) / (2 * a);  
}


