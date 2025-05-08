#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buku.h"
#include "utils.h"

void tambahBuku(Buku** head, char judul[], int stok) {
    Buku* newBuku = (Buku*)malloc(sizeof(Buku));
    strcpy(newBuku->judul, judul);
    newBuku->stok = stok;
    newBuku->antrian = NULL;
    newBuku->next = NULL;

    if (*head == NULL) {
        *head = newBuku;
    } else {
        Buku* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBuku;
    }
    printf("Buku %s ditambahkan.\n", judul);
}

Buku* cariBuku(Buku* head, const char* judul) {
    Buku* current = head;
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void tampilkanBuku(Buku* head) {
    Buku* current = head;
    printf("Daftar buku:\n");
    if (current == NULL) {
        printf("  (Kosong)\n");
        return;
    }
    while (current != NULL) {
        printf("- %s (Stok: %d)\n", current->judul, current->stok);
        current = current->next;
    }
}