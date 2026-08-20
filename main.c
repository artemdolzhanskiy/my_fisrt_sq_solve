#include <stdio.h>
#include <math.h>
#include <assert.h>


void priv(double a, double b, double c);
void poka(double x1, double x2);
void a_0(double a, double b, double c);
void b_0(double a, double b, double c);

void umn_vvod(double a, double b, double c);
double min_root_kv_ur(double a, double b, double c);
double max_root_kv_ur(double a, double b, double c);
double descriminant(double a, double b, double c);


int main(){
    printf("Hello! This program solve kv_ur. \nEnter input data: a, b, c: \n");

    double a = 0, b = 0, c = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    //umn_vvod(double &a, double &b, double &c);
    

    printf("%lf %lf %lf \n", a, b, c);

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


/*void umn_vvod(double a, double b, double c){
    char str[100];
    fgets(str, sizeof(str), stdin);
    int V = str[0];
    while
    
}*/


/*double umn_vvod(){
    double chislo = 0;
    int V;
    V = getchar();
    while(V == ' ' || V == '\n'){
        if (V == '1'){
            chislo = chislo * 10 + 1; 
        }else if (V == '2'){
            chislo = chislo * 10 + 2; 
        }else if (V == '3'){
            chislo = chislo * 10 + 3; 
        }else if (V == '4'){
            chislo = chislo * 10 + 4; 
        }else if (V == '5'){
            chislo = chislo * 10 + 5; 
        }else if (V == '6'){
            chislo = chislo * 10 + 6; 
        }else if (V == '7'){
            chislo = chislo * 10 + 7; 
        }else if (V == '8'){
            chislo = chislo * 10 + 8; 
        }else if (V == '9'){
            chislo = chislo * 10 + 9; 
        }else if (V == '0'){
            chislo = chislo * 10 + 0;
        }
        V = getchar();
    }
    return chislo;
}*/


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
