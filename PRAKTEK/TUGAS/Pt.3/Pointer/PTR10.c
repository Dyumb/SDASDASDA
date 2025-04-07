/* -------------------------------------------------------------- */
/* File : PTR10.cpp */
/* Deskripsi : Pointer dan fungsi/prosedur */
/* -------------------------------------------------------------- */

#include <stdio.h>

    /* Prototype */
    void f1(void); // penggunaan void agar jelas bahwa fungsi f1 tidak menerima parameter
    void f2(void);
    void f3(void);
    void f4(void);

    /* kamus Global */
    #define true 1
    #define false 0

    int quit = false; // penggunaan int karena false sudah di define menjadi 0

int main()
{
    /* kamus lokal */
    /* Definisi tabel yang elemennya adalah pointer ke fungsi */
    /* Elemen tabel yang ke - i akan mengakses fungsi ke - i */
    /* Pilihan menjadi indeks tabel, dan dipakai untuk mengaktifkan fungsi */
    /* yang sesuai */

    void (*tab[4]) () = {f1, f2, f3, f4}; /* Pointer ke procedure */
    // dengan *arr[], isi atau elemen dari array akan menjadi pointer juga

    /* program */
    printf("Pointer to function : \n");

    /* Menu */
    do
    {
    printf("Pilih salah satu : \n");
    printf("1. Buka file hanya untuk baca \n");
    printf("2. Tutup file \n");
    printf("3. Edit file \n");
    printf("4. Quit \n");
    tab[getchar() - '1'] () ; // getchar - '1' agar input menjadi sesuai dengan index array
                              // 1 dalam ASCII = 49, '1' - '1' == 49 - 49 = 0, jadi indexnya 0
    getchar(); /* untuk membuang return karakter */
    } while (!quit);
    return 0;
    }
    /* Body Function */
    void f1 ()
    {
    printf("Ini fungsi f1 \n");
    }

    void f2 ()
    {
    printf("Ini fungsi f2 \n");
    }
    void f3 ()
    {
    printf("Ini fungsi f3 \n");
    }
    void f4 ()
    {
    quit = true;
    printf("Quit ... \n");
}
