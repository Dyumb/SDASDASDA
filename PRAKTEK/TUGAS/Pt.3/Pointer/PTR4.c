/* --------------------------------------------------------- */
/* File Program : PTR4.CPP */
/* Contoh pemakaian pointer */
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){

    int z, s, *pz, *ps; // deklarasi var.

    z = 20; // assignment z
    s = 30; // assignment s
    pz = &z; // assignment pz dengan alamat z
    ps = &s; // assignment ps dengan alamat s
    *pz = *pz + *ps; // assignment *pz dengan *pz tambah *ps

    printf("z = %d, s = %d\n", z , s); // tampilkan output dari z dan s setelah proses

    return 0;

/* STUDI KASUS : */
/* - Eksekusi file program tersebut dan pahami maksud program ini */
/* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
/* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
