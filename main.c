#include <stdio.h>
#include <math.h>

double min_root_kv_ur(double a, double b, double c);
double max_root_kv_ur(double a, double b, double c);
double descriminant(double a, double b, double c);

int main(){
    printf("Hello! This program solve kv_ur. \nEnter input data: a, b, c: \n");

    double a = 0, b = 0, c = 0;
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;


    if (descriminant(a, b, c) == 0)
        printf("This equation has 1 root.\n");
    else if (descriminant(a, b, c) > 0)
        printf("This equation has 2 roots.\n");
    else
        printf("This equation hasn't roots.\n");

        
    if (descriminant(a, b, c) < 0){
        exit(0);
    }

    
    x1 = min_root_kv_ur(a, b, c);
    x2 = max_root_kv_ur(a, b, c);


    if (x1 == x2){
        printf("root %lf \n", x1);
    }
    else{
        printf("min_root %lf \n", x1);
        printf("max_root %lf \n", x2);
    }

    return 0;
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
