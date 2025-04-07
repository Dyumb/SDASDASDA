#include <stdio.h>

int main(){

    int i;
    int j;

    i = 1;
    j = 0;

    while(i <= 5){
        j = 0;
        while(j < i){
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}