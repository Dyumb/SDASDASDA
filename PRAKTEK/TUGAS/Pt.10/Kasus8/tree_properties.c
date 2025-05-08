
#include "nbtrees.h"
#include <stdio.h>

boolean Search(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return false;

    int stack[jml_maks + 1];
    int top = -1;
    stack[++top] = 1;

    while (top >= 0) {
        int idx = stack[top--];
        if (idx != nil && P[idx].info != '\0') {
            if (P[idx].info == X) return true;
            if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') stack[++top] = P[idx].ps_nb;
            if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') stack[++top] = P[idx].ps_fs;
        }
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    int count = 0, stack[jml_maks + 1], top = -1;
    stack[++top] = 1;

    while (top >= 0) {
        int idx = stack[top--];
        if (idx != nil && P[idx].info != '\0') {
            count++;
            if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') stack[++top] = P[idx].ps_nb;
            if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') stack[++top] = P[idx].ps_fs;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    int count = 0, stack[jml_maks + 1], top = -1;
    stack[++top] = 1;

    while (top >= 0) {
        int idx = stack[top--];
        if (idx != nil && P[idx].info != '\0') {
            if (P[idx].ps_fs == nil) count++;
            if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') stack[++top] = P[idx].ps_nb;
            if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') stack[++top] = P[idx].ps_fs;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return -1;
    int queue[jml_maks + 1], levels[jml_maks + 1], front = 0, rear = -1;
    queue[++rear] = 1;
    levels[rear] = 0;

    while (front <= rear) {
        int idx = queue[front], lvl = levels[front++];
        if (idx != nil && P[idx].info != '\0') {
            if (P[idx].info == X) return lvl;
            int child = P[idx].ps_fs;
            while (child != nil && P[child].info != '\0') {
                queue[++rear] = child;
                levels[rear] = lvl + 1;
                child = P[child].ps_nb;
            }
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    int queue[jml_maks + 1], levels[jml_maks + 1], front = 0, rear = -1, maxDepth = 0;
    queue[++rear] = 1;
    levels[rear] = 0;

    while (front <= rear) {
        int idx = queue[front], lvl = levels[front++];
        if (idx != nil && P[idx].info != '\0') {
            if (lvl > maxDepth) maxDepth = lvl;
            int child = P[idx].ps_fs;
            while (child != nil && P[child].info != '\0') {
                queue[++rear] = child;
                levels[rear] = lvl + 1;
                child = P[child].ps_nb;
            }
        }
    }
    return maxDepth;
}

int Max(infotype a, infotype b) {
    return (a > b) ? a : b;
}

void PrintNodeDetail(Isi_Tree T) {
    printf("Seluruh Node pada Non Binary Tree:\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (T[i].info != '\0') {
            printf("\n--> Indeks ke-%d\n", i);
            printf("-------------------------------------------------\n");
            printf("info array ke %d         : %c\n", i, T[i].info);
            printf("first son array ke %d    : %d\n", i, T[i].ps_fs);
            printf("next brother array ke %d : %d\n", i, T[i].ps_nb);
            printf("parent array ke %d       : %d\n", i, T[i].ps_pr);
            printf("-------------------------------------------------\n");
        }
    }
}
