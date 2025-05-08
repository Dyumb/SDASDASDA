#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_mode.h"
#include "sll_mode.h"
#include "dll_mode.h"
#include "stack.h"
#include "utils.h"

int main() {
    StackNode* stack = NULL;
    while (1) {
        printf("\n=== Sistem Perpustakaan ===\n");
        printf("1. Mode Array\n2. Mode SLL\n3. Mode DLL\n4. Keluar\n");
        printf("Pilih: ");
        int mode;
        scanf("%d", &mode);
        getchar();

        if (mode == 4) break;
        if (mode < 1 || mode > 3) {
            printf("Mode salah!\n");
            continue;
        }

        while (1) {
            printf("\n=== Mode %s ===\n", mode == 1 ? "Array" : mode == 2 ? "SLL" : "DLL");
            printf("1. Tambah Buku\n2. Tampilkan Buku\n3. Pinjam Buku\n4. Kembalikan Buku\n5. Batalkan Peminjaman\n6. Undo\n7. Kembali\n");
            printf("Pilih: ");
            int pilihan;
            scanf("%d", &pilihan);
            getchar();

            char judul[50], nama[50];
            int stok, prioritas;
            Aksi aksi;

            if (pilihan == 1) {
                printf("Judul buku: ");
                safeInput(judul, 50);
                printf("Stok: ");
                scanf("%d", &stok);
                getchar();
                if (mode == 1) tambahBukuArray(judul, stok);
                else if (mode == 2) tambahBukuSLL(judul, stok);
                else tambahBukuDLL(judul, stok);
            }
            else if (pilihan == 2) {
                if (mode == 1) tampilBukuArray();
                else if (mode == 2) tampilBukuSLL();
                else tampilBukuDLL();
            }
            else if (pilihan == 3) {
                printf("Nama peminjam: ");
                safeInput(nama, 50);
                printf("Prioritas (0=Umum, 1=Mahasiswa, 2=Dosen): ");
                scanf("%d", &prioritas);
                getchar();
                printf("Judul buku: ");
                safeInput(judul, 50);
                aksi.type = 1; // Peminjaman
                strcpy(aksi.nama, nama);
                strcpy(aksi.judul, judul);
                aksi.prioritas = prioritas;
                if (mode == 1) pinjamBukuArray(nama, prioritas, judul);
                else if (mode == 2) pinjamBukuSLL(nama, prioritas, judul);
                else pinjamBukuDLL(nama, prioritas, judul);
                pushAksi(&stack, aksi);
            }
            else if (pilihan == 4) {
                printf("Judul buku: ");
                safeInput(judul, 50);
                if (mode == 1) kembalikanBukuArray(judul);
                else if (mode == 2) kembalikanBukuSLL(judul);
                else kembalikanBukuDLL(judul);
            }
            else if (pilihan == 5) {
                printf("Nama peminjam: ");
                safeInput(nama, 50);
                printf("Judul buku: ");
                safeInput(judul, 50);
                aksi.type = 2; // Pembatalan
                strcpy(aksi.nama, nama);
                strcpy(aksi.judul, judul);
                aksi.prioritas = 0;
                if (mode == 1) batalkanPeminjamanArray(judul, nama);
                else if (mode == 2) batalkanPeminjamanSLL(judul, nama);
                else batalkanPeminjamanDLL(judul, nama);
                pushAksi(&stack, aksi);
            }
            else if (pilihan == 6) {
                Aksi undo = popAksi(&stack);
                if (undo.type == 0) {
                    printf("Tidak ada aksi untuk di-undo!\n");
                } else if (undo.type == 1) {
                    // Undo peminjaman: batalkan peminjaman
                    if (mode == 1) batalkanPeminjamanArray(undo.judul, undo.nama);
                    else if (mode == 2) batalkanPeminjamanSLL(undo.judul, undo.nama);
                    else batalkanPeminjamanDLL(undo.judul, undo.nama);
                    printf("Peminjaman %s untuk %s di-undo!\n", undo.nama, undo.judul);
                } else {
                    // Undo pembatalan: masuk antrian lagi
                    if (mode == 1) pinjamBukuArray(undo.nama, undo.prioritas, undo.judul);
                    else if (mode == 2) pinjamBukuSLL(undo.nama, undo.prioritas, undo.judul);
                    else pinjamBukuDLL(undo.nama, undo.prioritas, undo.judul);
                    printf("Pembatalan %s untuk %s di-undo!\n", undo.nama, undo.judul);
                }
            }
            else if (pilihan == 7) {
                while (!isStackEmpty(stack)) {
                    popAksi(&stack);
                }
                if (mode == 2) bebaskanBukuSLL();
                else if (mode == 3) bebaskanBukuDLL();
                break;
            }
            else {
                printf("Pilihan salah!\n");
            }
        }
    }
    return 0;
}