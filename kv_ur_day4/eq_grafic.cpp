#include "eq_grafic.h"

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

    
    if (vertex_x > 100 || vertex_x < -100 || vertex_y > 100 || vertex_y < -100){
        fprintf(file, "Sorry, vertex is too far of (0; 0)");
        return ;
    }
    

    //printf("21\n");

    char grafic[200][200] = {};
    for (int i = 0; i < 200; ++i){
        for (int j = 0; j < 200; ++j) {
            if (i == 100){
                grafic[i][j] = '-';
            }
            else if (j == 100){
                grafic[i][j] = '|';
            }
            else{
                grafic[i][j] = ' ';
            }
        }
    }


    for (int j = 0; j < 200; ++j){
        double x = j - 100;
        double y = eq.a * (x * x) + eq.b * x + eq.c;
        int i = int(y + 100);
        //printf("%d %d \n", i, j);
        if (i >= 200 || i <= 0){
            continue;
        }
        else {
            grafic[i][j] = 'x';
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
            fprintf(file,  " ");
        }
        fprintf(file, "\n");
    }


    fclose(file);
}