#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array_mode.h"
#include "peminjam.h"
#include "utils.h"

BukuArray perpustakaan[MAX_BUKU];
int jumlahBuku = 0;

void tambahBukuArray(char judul[], int stok) {
    if (jumlahBuku >= MAX_BUKU) {
        printf("Perpustakaan penuh!\n");
        return;
    }
    strcpy(perpustakaan[jumlahBuku].judul, judul);
    perpustakaan[jumlahBuku].stok = stok;
    perpustakaan[jumlahBuku].jumlahPeminjam = 0;
    jumlahBuku++;
    printf("Buku %s ditambahkan.\n", judul);
}

void tampilBukuArray() {
    printf("Daftar buku:\n");
    if (jumlahBuku == 0) {
        printf("  (Kosong)\n");
        return;
    }
    for (int i = 0; i < jumlahBuku; i++) {
        printf("- %s (Stok: %d)\n", perpustakaan[i].judul, perpustakaan[i].stok);
        if (perpustakaan[i].jumlahPeminjam > 0) {
            printf("  Antrian peminjam:\n");
            for (int j = 0; j < perpustakaan[i].jumlahPeminjam; j++) {
                printf("  - %s (Prioritas: %d)\n", perpustakaan[i].peminjam[j], perpustakaan[i].prioritas[j]);
            }
        }
    }
}

void pinjamBukuArray(char nama[], int prioritas, char judul[]) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judul) == 0) {
            if (perpustakaan[i].stok > 0) {
                perpustakaan[i].stok--;
                printf("%s meminjam %s.\n", nama, judul);
            } else {
                if (perpustakaan[i].jumlahPeminjam < 50) {
                    int pos = perpustakaan[i].jumlahPeminjam;
                    for (int j = 0; j < perpustakaan[i].jumlahPeminjam; j++) {
                        if (prioritas > perpustakaan[i].prioritas[j]) {
                            pos = j;
                            break;
                        }
                    }
                    for (int j = perpustakaan[i].jumlahPeminjam; j > pos; j--) {
                        strcpy(perpustakaan[i].peminjam[j], perpustakaan[i].peminjam[j-1]);
                        perpustakaan[i].prioritas[j] = perpustakaan[i].prioritas[j-1];
                    }
                    strcpy(perpustakaan[i].peminjam[pos], nama);
                    perpustakaan[i].prioritas[pos] = prioritas;
                    perpustakaan[i].jumlahPeminjam++;
                    printf("%s masuk antrian untuk %s.\n", nama, judul);
                } else {
                    printf("Antrian penuh!\n");
                }
            }
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}

void kembalikanBukuArray(char judul[]) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judul) == 0) {
            perpustakaan[i].stok++;
            if (perpustakaan[i].jumlahPeminjam > 0) {
                printf("%s meminjam %s dari antrian.\n", perpustakaan[i].peminjam[0], judul);
                perpustakaan[i].stok--;
                for (int j = 0; j < perpustakaan[i].jumlahPeminjam - 1; j++) {
                    strcpy(perpustakaan[i].peminjam[j], perpustakaan[i].peminjam[j + 1]);
                    perpustakaan[i].prioritas[j] = perpustakaan[i].prioritas[j + 1];
                }
                perpustakaan[i].jumlahPeminjam--;
            } else {
                printf("Buku %s dikembalikan.\n", judul);
            }
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}

void batalkanPeminjamanArray(char judul[], char nama[]) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judul) == 0) {
            for (int j = 0; j < perpustakaan[i].jumlahPeminjam; j++) {
                if (strcmp(perpustakaan[i].peminjam[j], nama) == 0) {
                    for (int k = j; k < perpustakaan[i].jumlahPeminjam - 1; k++) {
                        strcpy(perpustakaan[i].peminjam[k], perpustakaan[i].peminjam[k + 1]);
                        perpustakaan[i].prioritas[k] = perpustakaan[i].prioritas[k + 1];
                    }
                    perpustakaan[i].jumlahPeminjam--;
                    printf("Peminjaman %s untuk %s dibatalkan.\n", nama, judul);
                    return;
                }
            }
            printf("%s tidak ada di antrian untuk %s.\n", nama, judul);
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}