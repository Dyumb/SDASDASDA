/* ----------------------------------------------------- */
/* File Program : PTR6.CPP */
/* Deskripsi : pointer yang menunjuk ke array */
/* ---------------------------------------------------- */

#include <stdio.h>

int main(){
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    static int tgl_lahir[] = {18, 6, 1989}; // static agar nilai array tidak berubah
    int *ptgl;
    int i = 0;

    ptgl = tgl_lahir; // pointer ptgl akan menunjuk ke tgl_lahir[0] sebagai nilai default
    printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl); // menampilkan output dari value yang ada di alamat pointer ptgl

    while(i < 3){ // menampilkan output dari semua elemen di array
    printf("Nilai dari tgl_lahir[%d] = %d\n", i, tgl_lahir[i]);
    i++;
    }

    return 0;
}
/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
/* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/
