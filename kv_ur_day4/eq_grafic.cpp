#include "eq_grafic.h"

bool EqualityEpsGraf(double ob_1, double ob_2){
    return (fabs(ob_1 - ob_2) <= 1);
}

void EqGrafic(struct square_equation eq){
    FILE *file = fopen("file_for_grafic.txt", "w");
    
    if (file == NULL) {
        printf("I can't open file_for_grafic.txt\n");
        fclose(file);
        return;
    }

    fprintf(file, "Grafic of square equation %lgx^2 + %lgx + %lg = 0.\n", eq.a, eq.b, eq.c);
    
    
    double vertex_x = (-eq.b) / (2 * eq.a);
    double vertex_y = eq.a * (vertex_x * vertex_x) + eq.b * vertex_x + eq.c;

    if( (vertex_x > 100 || vertex_x < -100 || vertex_y > 100 || vertex_y < -100) && eq.a != 0 ){
        fprintf(file, "Sorry, vertex is too far of (0; 0)");
        return ;
    }
    
    //printf("21\n");

    char grafic[200][200] = {};
    for (int i = 0; i < 200; ++i){
        for (int j = 0; j < 200; ++j) {
            if (i == 101){
                grafic[i][j] = '-';
            }
            else if (j == 99){
                grafic[i][j] = '|';
            }
            else{
                grafic[i][j] = ' ';
            }
        }
    }

    int koord[200] = {};
    for (int j = 1; j < 199; ++j){
        for (int i = 1; i < 199; ++i){
            double x = j - 100;
            double y = i - 100;
            //printf("%d %d \n", i, j);
            double y_res = eq.a * x * x + eq.b * x + eq.c;
            if (y_res > 100 || y_res <= -100){
                continue;
            }
            if ( EqualityEpsGraf(y_res, y) ){
                koord[j] = i;
                grafic[i][j] = 'X';
            }
        }
    }
    for (int j = 1; j < 199; ++j){
        if (koord[j] == 0){
            continue;
        }

        if (eq.a > 0){
            for (int i = koord[j]; i < 200; ++i){
                grafic[i][j] = 'X';
                if (grafic[i][j-1] == 'X' || grafic[i][j+1] == 'X'){
                    break;
                }
            }
        }
        else if (eq.a < 0){
            for (int i = koord[j]; i > 0; --i){
                grafic[i][j] = 'X';
                if (grafic[i][j-1] == 'X' || grafic[i][j+1] == 'X'){
                    break;
                }
            }
        }
    }

    

    //printf("42\n");

    for (int i = 199; i >= 0; --i){
        for (int j = 0; j < 200; ++j){
            if (grafic[i][j] == ' '){
                fprintf(file,  "  ");
            }
            else if (grafic[i][j] == '-'){
                fprintf(file,  "--");
            }
            fprintf(file, "%c", grafic[i][j]);
            if (grafic[i][j] == 'X')
                fprintf(file,  "  ");
        }
        fprintf(file, "\n");
    }

    fclose(file);
}