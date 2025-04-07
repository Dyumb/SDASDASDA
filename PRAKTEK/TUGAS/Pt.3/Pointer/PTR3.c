/* --------------------------------------------------------- */
/* File Program : PTR3.CPP */
/* Contoh pengubahan isi suatu variabel melalui pointer */
/* Tujuan : Menggunakan type data pointer dan manipulasinya */
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){

    float d, *pd; // deklarasi var. d dan *pd sebagai float
    d = 54.5; // assignment var. d sebesar 54.5
    printf("Isi d semula = %g\n", d); // menampilkan output untuk var. d, output = 54.5

    pd = &d; // assignment var. ptr pd dengan alamat dari var. d
    *pd = *pd + 10; // assignment var *pd dengan nilai *pd ditambah 10, dimana karena pd menyimpan alamat d dan *pd otomatis menyimpan nilai asli dari d
                    // maka dengan kode *pd = *pd + 10 akan mengubah nilai asli dari d itu sendiri, karena yang diubah langsung dari alamatnya
    printf("Isi d kini = %g\n", d); // menampilkan output dari var. d, output = 64.5

    return 0;
}
