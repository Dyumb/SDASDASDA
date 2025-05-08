#ifndef DLL_MODE_H
#define DLL_MODE_H

typedef struct BukuDLL {
    char judul[50];
    int stok;
    struct Peminjam* antrian;
    struct BukuDLL* next;
    struct BukuDLL* prev;
} BukuDLL;

void tambahBukuDLL(char judul[], int stok);
void tampilBukuDLL();
void pinjamBukuDLL(char nama[], int prioritas, char judul[]);
void kembalikanBukuDLL(char judul[]);
void batalkanPeminjamanDLL(char judul[], char nama[]);
void bebaskanBukuDLL();

#endif