#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void pushAksi(StackNode** top, Aksi aksi) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->aksi = aksi;
    newNode->next = *top;
    *top = newNode;
}

Aksi popAksi(StackNode** top) {
    if (isStackEmpty(*top)) {
        Aksi empty = {0, "", "", 0};
        return empty;
    }
    StackNode* temp = *top;
    Aksi aksi = temp->aksi;
    *top = temp->next;
    free(temp);
    return aksi;
}

int isStackEmpty(StackNode* top) {
    return top == NULL;
}