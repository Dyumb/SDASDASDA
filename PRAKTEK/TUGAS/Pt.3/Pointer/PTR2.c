/* --------------------------------------------------------- */
/* File Program : PTR2.CPP */
/* Contoh pemakaian pointer yang salah */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){
    float *pu; // deklarasi var. ptr pu sebagai float
    float nu; // deklarasi var. nu sebagai float
    int u = 1234; // deklarasi var. u sebagai integer dengan nilai 1234

    pu = &u; // assignment untuk pu diisi alamat dari var. u
    nu = *pu; // assignment untuk nu diisi nilai dari alamat yang ada di var. ptr pu

    printf("u = %d\n", u); // menampilkan output untuk u berupa integer, output = 1234
    printf("nu = %f\n", nu); // menampilkan output untuk nu berupa float, output = 0,0000

    return 0;
}
