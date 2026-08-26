#include <stdio.h>

int main(int argc, char *argv[]){
    // char str[100];
    
    // fgets(str, 100, stdin);


    for (int i = 0; i < argc; ++i){
        printf("%s \n", argv[i]);
    }
    //printf("\n\n");
    return 0;
}