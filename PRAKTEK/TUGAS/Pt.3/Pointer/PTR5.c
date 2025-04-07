/* --------------------------------------------------------------------------------------------- */
/* File Program : PTR5.CPP */
/* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
/* --------------------------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

int main(){

    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    int i = 5, j; // deklarasi var.
    char c = 'X'; // deklarasi var.
    int *Ptri = (int *) malloc(4); // deklarasi var. dan alokasi memori sebesar 4 byte (seukuran int)
    int *Ptrj = (int *) malloc(sizeof(int)); // deklarasi var. dan alokasi memori sebesar ukuran int (4 byte)
    float *fx = (float *) malloc(sizeof(float)); // deklarasi var. dan alokasi memori sebesar ukuran float (4 byte)
    int A[5]; // deklarasi var.
    float f = 7.23; // deklarasi var.

    /* program */
    *Ptri = 8; // inisialisasi var.
    *Ptrj = 0; // inisialisasi var.
    *fx = 3; // inisialisasi var.

    printf("Alamat i = %x \n", &i);
    printf("Nilai i = %d \n", i);
    printf("Ukuran int = %d byte\n\n", sizeof(int));
    printf("Alamat j = %x \n", &j);
    printf("Nilai j = %d \n", j); // nilai j = nilai sampah
    printf("Alamat c = %x \n", &c);
    printf("Nilai c = %c \n", c);
    printf("Ukuran char = %d byte\n\n", sizeof(char));

    printf("Alamat Ptri = %x \n", &Ptri);
    printf("Isi var Ptri = %x \n", Ptri); // nilai Ptri = nilai sampah
    printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri);
    printf("Ukuran pointer int = %d byte\n\n", sizeof(int *));

    printf("Alamat Ptrj = %x \n", &Ptrj);
    printf("Isi var Ptrj = %x \n", Ptrj); // nilai Ptrj = nilai sampah
    printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj);
    Ptrj = Ptri;
    printf("Isi var Ptrj sekarang = %x \n", Ptrj); // nilai Ptrj = nilai Ptri
    printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj);

    printf("Alamat A = %x \n", &A);
    printf("Isi var A = %x \n", A[3]); // nilai array di index ke-3, 0 karena belum di inisialisasi
    printf("Ukuran array A = %d byte\n\n", sizeof(A));

    printf("Alamat f = %x \n", &f);
    printf("Nilai f = %f \n", f);
    printf("Ukuran float = %d byte\n\n", sizeof(float));

    return 0;
}
