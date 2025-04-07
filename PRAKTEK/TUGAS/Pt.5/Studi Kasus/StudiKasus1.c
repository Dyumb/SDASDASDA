#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudiKasus1.h"


void createList(List *L){
    L->first = NULL;
}

address createNode(const char *nama, int nilai){
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        strcpy(newNode->info.nama, nama);
        newNode->info.nilai = nilai;
        newNode->next = NULL;
    }
}

int isEmpty(List L) {
    return (L.first == NULL);
}

void insertAkhir(List *L, const char *nama, int nilai) {
    address newNode = createNode(nama, nilai);
    if (newNode != NULL) {
        if (isEmpty(*L)) {
            L->first = newNode;
        } else {
            address temp = L->first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void deleteDuplicate(List *L) {
    address temp = L->first;
    while (temp != NULL) {
        address temp2 = temp;
        while (temp2->next != NULL) {
            if (strcmp(temp->info.nama, temp2->next->info.nama) == 0) {
                address toDelete = temp2->next;
                temp2->next = temp2->next->next;
                free(toDelete);
            } else {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

void printList(List *L){
    address temp = L->first;
    printf("Link-List Mahasiswa :\n");
    while (temp != NULL) {
        printf("%s %d\n", temp->info.nama, temp->info.nilai);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAll(List *L) {
    while (L->first != NULL) {
        address temp = L->first;
        L->first = L->first->next;
        free(temp);
    }
}

void copyList(List *L1, List *L2) {
    address temp = L1->first;
    while (temp != NULL) {
        if (temp->info.nilai > 70) { // Filter nilai di dalam loop, bukan di kondisi while
            insertAkhir(L2, temp->info.nama, temp->info.nilai);
        }
        temp = temp->next;
    }
}


void namaAscending(List *L) {
    address temp = L->first;
    while (temp != NULL) {
        address temp2 = temp->next;
        while (temp2 != NULL) {
            if (strcmp(temp->info.nama, temp2->info.nama) > 0) {
                Mahasiswa tempInfo = temp->info;
                temp->info = temp2->info;
                temp2->info = tempInfo;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void nilaiDescending(List *L) {
    address temp = L->first;
    while (temp != NULL) {
        address temp2 = temp->next;
        while (temp2 != NULL) {
            if (temp->info.nilai < temp2->info.nilai) {
                Mahasiswa tempInfo = temp->info;
                temp->info = temp2->info;
                temp2->info = tempInfo;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

int hitungMahasiswa(List *L) {
    int count = 0;
    address temp = L->first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}