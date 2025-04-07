/* -------------------------------------------------- */
/* File Program : PTR9.CPP */
/* Deskripsi : pointer yang menunjuk pointer */
/* -------------------------------------------------- */
#include <stdio.h>

int main()
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    int var_x = 273; // inisialisasi var_x
    int *ptr1; /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
    /* (Boleh disebut pointer integer saja) */

    int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
    /* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer saja) */

    ptr1 = &var_x; // inisialiasi pointer ptr1 menunjuk ke alamar var_x
    ptr2 = &ptr1; // inisialisasi pointer ptr2 menunjuk ke alamat ptr1

    /* Mengakses nilai var_x melalui ptr1 dan ptr2 */
    printf("Nilai var_x = %d\n", *ptr1); // menampilkan output dari value yang ada di alamat yang ditunjuk oleh ptr1
    printf("Nilai var_x = %d\n", **ptr2); // menampilkan output dari value yang ada di alamat yang ditunjuk oleh ptr1

    return 0;
}
