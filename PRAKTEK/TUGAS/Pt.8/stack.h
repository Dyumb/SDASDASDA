#ifndef STACK_H
#define STACK_H

typedef struct {
    int type;
    char nama[50];
    char judul[50];
    int prioritas;
} Aksi;

typedef struct StackNode {
    Aksi aksi;
    struct StackNode* next;
} StackNode;

void pushAksi(StackNode** top, Aksi aksi);
Aksi popAksi(StackNode** top);
int isStackEmpty(StackNode* top);

#endif