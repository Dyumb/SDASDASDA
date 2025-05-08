#ifndef PEMINJAM_H
#define PEMINJAM_H

typedef struct Peminjam {
    char nama[50];
    int prioritas;
    struct Peminjam* next;
} Peminjam;

void tambahPeminjam(Peminjam** head, char nama[], int prioritas);
void tampilAntrian(Peminjam* head);
Peminjam* ambilPeminjamBerikut(Peminjam** head);

#endif