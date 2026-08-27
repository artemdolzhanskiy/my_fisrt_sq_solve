#include "eq_menu.h"

void Eq_Help(){
    printf( "-help - get information about this program\n"
            "-enter_test - user can enter test\n"
            "-auto_test - program start autotesting\n"
            "-test_from_file - program start testing on data from file file_with_data.txt\n"
            "-training - program can help you training solve square equation\n"
            "-write_test_to_file - program write a b c(from user), n_roots, x1, x2(from program) in file_for_writing.txt\n"
            "-draw_grafic - program draw a grafic on results of test from user to file_for_grafic.txt\n");
}

void Eq_Enter_Test(){
    while (true){
        printf("Please enter data\n");

        struct square_equation eq = InputEq();

        eq = SolveEq(eq);

        PrintEq(eq);


        printf("Do you want to write results of last test to file_for_writing.txt?\n");
        printf("Enter 1 if YES or 0 if NO:  ");

        int choose1 = 0;
        scanf("%d", &choose1);
        printf("As you command, my lord.\n\n");
        if (choose1){
            PrintEqFile(eq);
        }

        printf("Do you want to draw a grafic on results of last test to file_for_grafic.txt?\n");
        printf("Enter 1 if YES or 0 if NO:  ");
        scanf("%d", &choose1);
        printf("As you command, my lord.\n\n");
        if (choose1){
            EqGrafic(eq);
        }


        printf("Do you want to try again?\n");
        printf("Enter 1 or 0:  ");
        scanf("%d", &choose1);
        printf("As you command, my lord.\n\n");
        if (choose1 != 1){
            exit(0);
        }
    }
}

void Eq_Auto_Test(){
    RunTests();
}

void Eq_Test_From_File(){
    printf("\nOK! Starting testing on data from file file_with_data.txt\n");

    int k_test_before = 0;
    while (true){
        struct square_equation eq = InputEqFile(k_test_before);
        
        if (isnan(eq.a) && isnan(eq.b) && isnan(eq.c))
            break;

        k_test_before += 1;

        if (isnan(eq.a) || isnan(eq.b) || isnan(eq.c)){
            printf("I can't reed %d test\n\n", k_test_before);
            break;
        }

        eq = SolveEq(eq);

        if (isnan(eq.a))
            break;
        
        PrintEq(eq);

    }
}

void Eq_Training(){
    while (true){
        printf("\nOK! You can try solve square equations from file_with_data.txt\n\n");
        printf("At first enter how many roots and when enter them all whith eps = 0.001.\n\n");

        StartTraining();
        
        printf("Tests ran out. Good luck!\n\n");

    }
}

void Eq_Write_Test_To_File(){
    printf("Please enter data\n");
    struct square_equation eq = InputEq();
    eq = SolveEq(eq);

    PrintEqFile(eq);
    printf("Mission completed, my lord\n\n");

}

void Eq_Draw_Grafic(){
    printf("Please enter data\n");
    struct square_equation eq = InputEq();
    eq = SolveEq(eq);

    EqGrafic(eq);
    printf("Mission completed, my lord\n\n");
}