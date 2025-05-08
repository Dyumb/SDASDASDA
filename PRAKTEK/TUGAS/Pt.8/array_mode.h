#ifndef ARRAY_MODE_H
#define ARRAY_MODE_H

#define MAX_BUKU 50

typedef struct {
    char judul[50];
    int stok;
    char peminjam[50][50];
    int prioritas[50];
    int jumlahPeminjam;
} BukuArray;

extern BukuArray perpustakaan[MAX_BUKU];
extern int jumlahBuku;

void tambahBukuArray(char judul[], int stok);
void tampilBukuArray();
void pinjamBukuArray(char nama[], int prioritas, char judul[]);
void kembalikanBukuArray(char judul[]);
void batalkanPeminjamanArray(char judul[], char nama[]);

#endif