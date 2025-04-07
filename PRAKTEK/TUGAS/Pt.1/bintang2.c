#include <stdio.h>

int main(){

    int i;
    int j;
    int k;


    i = 1;

    while(i <= 5){
        j = 5;
        while(j > i){
            printf(" ");
            j--;
        }

        k = 0;
        while(k < i){
            printf("*");
            ++k;
        }
        printf("\n");
        i++;
    }
    return 0;
}