#include "kota.h"

void InsertName(CityNode** list, char* kt, char* nm) {
    CityNode* current = *list;
    while (current != NULL && strcmp(current->kota, kt) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        InsertCity(list, kt);
        current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
    }
    InsertNode(&(current->p), nm);
}

void DeleteName(CityNode** list, char* kt, char* nm) {
    CityNode* current = *list;
    while (current != NULL && strcmp(current->kota, kt) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Kota %s tidak ditemukan.\n", kt);
        return;
    }
    DeleteNode(&(current->p), nm);
}

void DeleteElement(CityNode** list, char* kt) {
    DeleteCity(list, kt);
}

void PrintStructure(CityNode* list) {
    if (list == NULL) {
        printf("Data kosong.\n");
        return;
    }
    CityNode* current = list;
    while (current != NULL) {
        printf("Kota: %s -> ", current->kota);
        PrintList(current->p);
        printf(" (Jumlah nama: %d)\n", CountNodes(current->p));
        current = current->next;
    }
    printf("Total kota: %d\n", CountCities(list));
    printf("Total nama: %d\n", CountTotalNames(list));
}

int CountTotalNames(CityNode* list) {
    int total = 0;
    CityNode* current = list;
    while (current != NULL) {
        total += CountNodes(current->p);
        current = current->next;
    }
    return total;
}
