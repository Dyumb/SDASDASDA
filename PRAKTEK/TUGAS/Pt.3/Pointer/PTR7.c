/* ----------------------------------------------------------- */
/* File Program : PTR7.CPP */
/* (Pointer dan String bagian ke-1) */
/* Deskripsi : pointer yang menunjuk ke data string */
/* ---------------------------------------------------------- */
#include <stdio.h>

int main()
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char *pkota = "BANDUNG"; // pointer pkota akan menunjuk ke string konstan BANDUNG yang bersifat read only
    puts(pkota);
    return 0;
}
/* STUDI KASUS : */
/* Apa perbedaan deklarasi variabel char *pkota='BANDUNG'; dengan char kota[]='BANDUNG' ?
*/
