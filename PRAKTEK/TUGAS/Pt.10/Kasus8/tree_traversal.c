
#include "nbtrees.h"
#include <stdio.h>

void PreOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        int stack[jml_maks + 1];
        int top = -1;
        stack[++top] = 1;

        while (top >= 0) {
            int idx = stack[top--];
            if (idx != nil && P[idx].info != '\0') {
                printf("%c ", P[idx].info);
                if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') stack[++top] = P[idx].ps_nb;
                if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') stack[++top] = P[idx].ps_fs;
            }
        }
    }
}

void InOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        int stack[jml_maks + 1];
        int top = -1;
        int idx = 1;

        while (top >= 0 || (idx != nil && P[idx].info != '\0')) {
            while (idx != nil && P[idx].info != '\0') {
                stack[++top] = idx;
                idx = P[idx].ps_fs;
            }

            if (top >= 0) {
                idx = stack[top--];
                printf("%c ", P[idx].info);
                idx = P[idx].ps_nb;
            }
        }
    }
}

void PostOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        int stack[jml_maks + 1];
        int top = -1;
        int idx = 1;
        int lastVisited = nil;

        while (top >= 0 || (idx != nil && P[idx].info != '\0')) {
            while (idx != nil && P[idx].info != '\0') {
                stack[++top] = idx;
                idx = P[idx].ps_fs;
            }

            if (top >= 0) {
                idx = stack[top];
                if (P[idx].ps_nb == nil || P[idx].ps_nb == lastVisited) {
                    printf("%c ", P[idx].info);
                    lastVisited = idx;
                    top--;
                    idx = nil;
                } else {
                    idx = P[idx].ps_nb;
                }
            }
        }
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) return;

    int queue[jml_maks + 1];
    int front = 0, rear = -1;
    queue[++rear] = 1;

    while (front <= rear) {
        int current = queue[front++];
        if (current <= Maks_node && X[current].info != '\0') {
            printf("%c ", X[current].info);
            int child = X[current].ps_fs;
            while (child != nil && child <= Maks_node) {
                if (X[child].info != '\0') queue[++rear] = child;
                child = X[child].ps_nb;
            }
        }
    }
}

void PrintTree(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong\n");
        return;
    }

    int stack[jml_maks + 1];
    int level[jml_maks + 1];
    int top = -1;
    stack[++top] = 1;
    level[top] = 0;

    while (top >= 0) {
        int idx = stack[top];
        int lvl = level[top--];

        if (idx != nil && P[idx].info != '\0') {
            for (int i = 0; i < lvl; i++) printf("  ");
            printf("%c\n", P[idx].info);

            int child = P[idx].ps_fs;
            int nextChild = nil;
            while (child != nil && P[child].info != '\0') {
                nextChild = P[child].ps_nb;
                stack[++top] = child;
                level[top] = lvl + 1;
                child = nextChild;
            }
        }
    }
}
