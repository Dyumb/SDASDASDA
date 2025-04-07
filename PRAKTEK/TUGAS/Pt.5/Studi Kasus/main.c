#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudiKasus1.h"
#include "StudiKasus1.c"

int main(){
    
    List L1, L2;

    createList(&L1);
    createList(&L2);

    insertAkhir(&L1, "Udin", 85);
    insertAkhir(&L1, "Budi", 80);
    insertAkhir(&L1, "Suki", 70);
    insertAkhir(&L1, "Joko", 60);
    insertAkhir(&L1, "Udin", 90);
    insertAkhir(&L1, "Siti", 50);
    insertAkhir(&L1, "Oliver", 90);
    insertAkhir(&L1, "Ambatu", 100);
    printf("Sebelum Diurutkan\n");
    printList(&L1);

    printf("\nSetelah Diurutkan (Nama)\n");

    namaAscending(&L1);
    printList(&L1);

    printf("\nSetelah Diurutkan (Nilai)\n");

    nilaiDescending(&L1);
    printList(&L1);

    int a = hitungMahasiswa(&L1);
    printf("\nJumlah Mahasiswa : %d\n", a);

    copyList(&L1, &L2);
    printf("\nList L2 (Sebelum penghapusan duplikat)\n");
    printList(&L2);

    printf("\nList L2 (Setelah penghapusan duplikat)\n");
    deleteDuplicate(&L2);
    printList(&L2);

    deleteAll(&L1);
    deleteAll(&L2);
}