#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sll_mode.h"
#include "buku.h"
#include "peminjam.h"
#include "utils.h"

Buku* headBukuSLL = NULL;

void tambahBukuSLL(char judul[], int stok) {
    tambahBuku(&headBukuSLL, judul, stok);
}

void tampilBukuSLL() {
    Buku* current = headBukuSLL;
    printf("Daftar buku:\n");
    if (current == NULL) {
        printf("  (Kosong)\n");
        return;
    }
    while (current != NULL) {
        printf("- %s (Stok: %d)\n", current->judul, current->stok);
        if (current->antrian != NULL) {
            tampilAntrian(current->antrian);
        }
        current = current->next;
    }
}

void pinjamBukuSLL(char nama[], int prioritas, char judul[]) {
    Buku* buku = cariBuku(headBukuSLL, judul);
    if (buku == NULL) {
        printf("Buku tidak ditemukan!\n");
        return;
    }
    if (buku->stok > 0) {
        buku->stok--;
        printf("%s meminjam %s.\n", nama, judul);
    } else {
        tambahPeminjam(&(buku->antrian), nama, prioritas);
        printf("%s masuk antrian untuk %s.\n", nama, judul);
    }
}

void kembalikanBukuSLL(char judul[]) {
    Buku* buku = cariBuku(headBukuSLL, judul);
    if (buku == NULL) {
        printf("Buku tidak ditemukan!\n");
        return;
    }
    buku->stok++;
    Peminjam* peminjam = ambilPeminjamBerikut(&(buku->antrian));
    if (peminjam != NULL) {
        buku->stok--;
        printf("%s meminjam %s dari antrian.\n", peminjam->nama, judul);
        free(peminjam);
    } else {
        printf("Buku %s dikembalikan.\n", judul);
    }
}

void batalkanPeminjamanSLL(char judul[], char nama[]) {
    Buku* buku = cariBuku(headBukuSLL, judul);
    if (buku == NULL) {
        printf("Buku tidak ditemukan!\n");
        return;
    }
    Peminjam* current = buku->antrian;
    Peminjam* prev = NULL;
    while (current != NULL && strcmp(current->nama, nama) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("%s tidak ada di antrian untuk %s.\n", nama, judul);
        return;
    }
    if (prev == NULL) {
        buku->antrian = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Peminjaman %s untuk %s dibatalkan.\n", nama, judul);
}

void bebaskanBukuSLL() {
    Buku* current = headBukuSLL;
    while (current != NULL) {
        Buku* temp = current;
        current = current->next;
        Peminjam* peminjam = temp->antrian;
        while (peminjam != NULL) {
            Peminjam* tempPeminjam = peminjam;
            peminjam = peminjam->next;
            free(tempPeminjam);
        }
        free(temp);
    }
    headBukuSLL = NULL;
}