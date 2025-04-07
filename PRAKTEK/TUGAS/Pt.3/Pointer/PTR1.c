/* --------------------------------------------------------- */
/* File Program : PTR1.CPP */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h>
int main(){
    int x, y; // deklarasi var. x dan y
    int *px, *py; // deklarasi var. pointer px (dan py)

    x = 87; // assignment nilai x sebesar 87(int)
    px = &x; // assignment nilai px dengan alamat dari var. x
    y = *px; // assignment nilai y dengan nilai dari alamat yang disimpan oleh pointer px
    py = &y; // assignment nilai py dengan alamat dari var. y

    printf("Alamat x = %p\n", &x);
    printf("Isi px = %d\n", *px);
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);
    printf("Nilai y = %d\n", y);
    printf("Alamat dari y = %p\n", py);

    return 0;

    // jika y = *px dulu sebelum px = &x, maka program akan crash dan tidak menampilkan apa apa.
}
