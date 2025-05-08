#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dll_mode.h"
#include "peminjam.h"
#include "utils.h"

BukuDLL* headBukuDLL = NULL;

void tambahBukuDLL(char judul[], int stok) {
    BukuDLL* newBuku = (BukuDLL*)malloc(sizeof(BukuDLL));
    strcpy(newBuku->judul, judul);
    newBuku->stok = stok;
    newBuku->antrian = NULL;
    newBuku->next = NULL;
    newBuku->prev = NULL;

    if (headBukuDLL == NULL) {
        headBukuDLL = newBuku;
    } else {
        BukuDLL* current = headBukuDLL;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBuku;
        newBuku->prev = current;
    }
    printf("Buku %s ditambahkan.\n", judul);
}

void tampilBukuDLL() {
    BukuDLL* current = headBukuDLL;
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

void pinjamBukuDLL(char nama[], int prioritas, char judul[]) {
    BukuDLL* current = headBukuDLL;
    while (current != NULL && strcmp(current->judul, judul) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Buku tidak ditemukan!\n");
        return;
    }
    if (current->stok > 0) {
        current->stok--;
        printf("%s meminjam %s.\n", nama, judul);
    } else {
        tambahPeminjam(&(current->antrian), nama, prioritas);
        printf("%s masuk antrian untuk %s.\n", nama, judul);
    }
}

void kembalikanBukuDLL(char judul[]) {
    BukuDLL* current = headBukuDLL;
    while (current != NULL && strcmp(current->judul, judul) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Buku tidak ditemukan!\n");
        return;
    }
    current->stok++;
    Peminjam* peminjam = ambilPeminjamBerikut(&(current->antrian));
    if (peminjam != NULL) {
        current->stok--;
        printf("%s meminjam %s dari antrian.\n", peminjam->nama, judul);
        free(peminjam);
    } else {
        printf("Buku %s dikembalikan.\n", judul);
    }
}

void batalkanPeminjamanDLL(char judul[], char nama[]) {
    BukuDLL* current = headBukuDLL;
    while (current != NULL && strcmp(current->judul, judul) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Buku tidak ditemukan!\n");
        return;
    }
    Peminjam* peminjam = current->antrian;
    Peminjam* prev = NULL;
    while (peminjam != NULL && strcmp(peminjam->nama, nama) != 0) {
        prev = peminjam;
        peminjam = peminjam->next;
    }
    if (peminjam == NULL) {
        printf("%s tidak ada di antrian untuk %s.\n", nama, judul);
        return;
    }
    if (prev == NULL) {
        current->antrian = peminjam->next;
    } else {
        prev->next = peminjam->next;
    }
    free(peminjam);
    printf("Peminjaman %s untuk %s dibatalkan.\n", nama, judul);
}

void bebaskanBukuDLL() {
    BukuDLL* current = headBukuDLL;
    while (current != NULL) {
        BukuDLL* temp = current;
        current = current->next;
        Peminjam* peminjam = temp->antrian;
        while (peminjam != NULL) {
            Peminjam* tempPeminjam = peminjam;
            peminjam = peminjam->next;
            free(tempPeminjam);
        }
        free(temp);
    }
    headBukuDLL = NULL;
}