#ifndef BUKU_H
#define BUKU_H

#include "peminjam.h"

typedef struct Buku {
    char judul[50];
    int stok;
    struct Peminjam* antrian;
    struct Buku* next;
} Buku;

void tambahBuku(Buku** head, char judul[], int stok);
void tampilkanBuku(Buku* head);
Buku* cariBuku(Buku* head, const char* judul);

#endif