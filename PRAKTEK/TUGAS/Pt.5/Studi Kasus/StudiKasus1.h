#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50]; // Nama mahasiswa (string)
    int nilai;     // Nilai UTS
} Mahasiswa;

typedef struct tElmtList *address;
typedef struct tElmtList {
    Mahasiswa info;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

void createList(List *L);
address createNode(const char *nama, int nilai);
int iEmpty(List L);
void insertAkhir(List *L, const char *nama, int nilai);
void deleteDuplicate(List *L);
void printList(List *L);
void deleteAll(List *L);
void copyList(List *L1, List *L2);
void namaAscending(List *L);
void nilaiDescending(List *L);
int hitungMahasiswa(List *L);

#endif

