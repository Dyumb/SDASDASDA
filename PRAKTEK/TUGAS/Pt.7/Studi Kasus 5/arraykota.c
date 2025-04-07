#include "arraykota.h"

void InitArray(ArrayNRLL* array) {
    array->count = 0;
    for (int i = 0; i < MAX_KOTA; i++) {
        array->elements[i].p = NULL;
    }
}

int AddElementToArray(ArrayNRLL* array, char* kt) {
    for (int i = 0; i < array->count; i++) {
        if (strcmp(array->elements[i].kota, kt) == 0) {
            return i;
        }
    }
    if (array->count >= MAX_KOTA) {
        printf("Array penuh, tidak bisa menambah kota baru.\n");
        return -1;
    }
    array->elements[array->count] = CreateElement(kt);
    return array->count++;
}

void DeleteElement(ArrayNRLL* array, char* kt) {
    int idx = -1;
    for (int i = 0; i < array->count; i++) {
        if (strcmp(array->elements[i].kota, kt) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Kota %s tidak ditemukan.\n", kt);
        return;
    }

    Node* current = array->elements[idx].p;
    while (current != NULL) {
        Node* temp = current;
        current = current->q;
        free(temp);
    }

    for (int i = idx; i < array->count - 1; i++) {
        array->elements[i] = array->elements[i + 1];
    }

    array->count--;
}

int CountElements(ArrayNRLL* array) {
    return array->count;
}

void InsertName(ArrayNRLL* array, char* kt, char* nm) {
    int idx = AddElementToArray(array, kt);
    if (idx != -1) {
        InsertNode(&(array->elements[idx].p), nm);
    }
}

void DeleteName(ArrayNRLL* array, char* kt, char* nm) {
    int idx = -1;
    for (int i = 0; i < array->count; i++) {
        if (strcmp(array->elements[i].kota, kt) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("Kota %s tidak ditemukan.\n", kt);
        return;
    }
    DeleteNode(&(array->elements[idx].p), nm);
}

void PrintStructure(ArrayNRLL* array) {
    if (array->count == 0) {
        printf("Data kosong.\n");
        return;
    }
    for (int i = 0; i < array->count; i++) {
        printf("Kota: %s -> ", array->elements[i].kota);
        PrintList(array->elements[i].p);
        printf(" (Jumlah nama: %d)\n", CountNodes(array->elements[i].p));
    }
    printf("Total kota: %d\n", CountElements(array));
    printf("Total nama: %d\n", CountTotalNames(array));
}

int CountTotalNames(ArrayNRLL* array) {
    int total = 0;
    for (int i = 0; i < array->count; i++) {
        total += CountNodes(array->elements[i].p);
    }
    return total;
}