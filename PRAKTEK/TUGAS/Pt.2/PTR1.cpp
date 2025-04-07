/* --------------------------------------------------------- */
/* File Program : PTR1.CPP */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){
    int x, y; // deklarasi variabel x dan y

    int *px; // deklarasi pointer px
    x = 87; // proses assignment untuk var. x

    px = &x; // pointer px menunjuk ke alamat var. x
    y = *px;

    printf("Alamat x = %p\n", &x);
    printf("Isi px = %d\n", x);
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);
    printf("Nilai y = %p\n", y);
return 0;
}
