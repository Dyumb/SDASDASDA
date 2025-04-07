/* Nama Program : mdate.c
	Deskripsi : Driver untuk menggunakan unit ADT Date
			yang ada di date.h dan date.c
*/

#include <stdio.h>
#include <conio.h>
#include "date.h"

int main() {
    date D1, D2, D3;

    CreateDate(&D1);
    printf("Hasil CreateDate (&D1), maka D1 bernilai : %d/%d/%d\n", D1.Tgl, D1.Bln, D1.Thn);
    printf("Tanggal : %d\nBulan : %d\nTahun : %d\n", D1.Tgl, D1.Bln, D1.Thn);

    // Input D2 sebagai tanggal ke-dua
    printf("Masukkan tanggal ke-2\n");
    ReadDate(&D2);
    int tglAkhir = getEndDate(D2);
    printf("Batas tanggal : %d\n", tglAkhir);

    if (isValid(D2) == false){
        printf("Tanggal yang dimasukkan tidak valid!\n");
    }

    printf("Setelah perintah BacaDate(&D2), maka D2 bernilai : %d/%d/%d\n", D2.Tgl, D2.Bln, D2.Thn);

    // Cek apakah tahun D2 adalah tahun kabisat
    if (isKabisat(D2)) {
        printf("Tahun %d adalah tahun kabisat\n", D2.Thn);
    } else {
        printf("Tahun %d bukan tahun kabisat\n", D2.Thn);
    }

    // Menampilkan tanggal sebelum D2
    DateBefore(D2);

    // Menampilkan tanggal sesudah D2
    NextDate(D2);

    // Input D3 sebagai tanggal ketiga
    printf("\nTanggal : ");
    scanf("%d", &D3.Tgl);
    printf("Bulan : ");
    scanf("%d", &D3.Bln);
    printf("Tahun : ");
    scanf("%d", &D3.Thn);

    printf("Setelah perintah BacaDate(&D3), maka D3 bernilai : %d/%d/%d\n", D3.Tgl, D3.Bln, D3.Thn);

    // 7. Hitung selisih hari antara D2 dan D3
    SelisihDate(D2, D3);

    // 8. Menanyakan apakah ingin mengulang atau tidak
    char ulang;
    printf("\nCoba lagi ? (y/t) ");
    scanf(" %c", &ulang);

    if (ulang == 'y' || ulang == 'Y') {
        main(); // Memanggil kembali main untuk pengulangan
    } else {
        printf("Program selesai.\n");
    }

    return 0;
}
