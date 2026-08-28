#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eq_menu.h"


int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Enter      ./a.exe -help      for info.\n\n");
        exit(0);
        
    }

    if (!strcmp(argv[1], "-help")){
        Eq_Help();

    }
    else if (!strcmp(argv[1], "-enter_test")){
        Eq_Enter_Test();

    }
    else if (!strcmp(argv[1], "-auto_test")){
        printf("OK! Starting autotesting\n\n");

        Eq_Auto_Test();

    }
    else if (!strcmp(argv[1], "-test_from_file")){
        Eq_Test_From_File();

    }
    else if (!strcmp(argv[1], "-training")){
        Eq_Training();

    }
    else if (!strcmp(argv[1], "-write_test_to_file")){
        Eq_Write_Test_To_File();

    }
    else if (!strcmp(argv[1], "-draw_grafic")){
        Eq_Draw_Grafic();

    }
    else {
        printf("Sorry, i don't understand.\n\n");

    }

    return 0;
}