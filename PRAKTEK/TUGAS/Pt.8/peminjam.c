#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "peminjam.h"
#include "utils.h"

void tambahPeminjam(Peminjam** head, char nama[], int prioritas) {
    Peminjam* newPeminjam = (Peminjam*)malloc(sizeof(Peminjam));
    strcpy(newPeminjam->nama, nama);
    newPeminjam->prioritas = prioritas;
    newPeminjam->next = NULL;

    if (*head == NULL || prioritas > (*head)->prioritas) {
        newPeminjam->next = *head;
        *head = newPeminjam;
    } else {
        Peminjam* current = *head;
        while (current->next != NULL && current->next->prioritas >= prioritas) {
            current = current->next;
        }
        newPeminjam->next = current->next;
        current->next = newPeminjam;
    }
}

void tampilAntrian(Peminjam* head) {
    Peminjam* current = head;
    printf("Antrian peminjam:\n");
    if (current == NULL) {
        printf("  (Kosong)\n");
        return;
    }
    while (current != NULL) {
        printf("- %s (Prioritas: %d)\n", current->nama, current->prioritas);
        current = current->next;
    }
}

Peminjam* ambilPeminjamBerikut(Peminjam** head) {
    if (*head == NULL) return NULL;
    
    Peminjam* ambil = *head;
    *head = (*head)->next;
    ambil->next = NULL;
    
    return ambil;
}