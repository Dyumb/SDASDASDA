#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "nbtrees.h"

void Create_Tree(Isi_Tree X, int Jml_Node) {
    // inisialisasi array
    int i = 1;
    while (i <= jml_maks) {
        X[i].info = '\0';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
        i++;
    }

    // buat node
    if (Jml_Node <= jml_maks && Jml_Node >= 0){
        if (Jml_Node >= 1) {
            int root = 1;
            X[root].info = 'A';
            X[root].ps_pr = 0;
            X[root].ps_nb = 0;
            X[root].ps_fs = 0;

            srand(time(NULL));

            int queue[jml_maks + 1];
            int front = 0;
            int rear = -1;
            int node_dibuat = 1; // dari root
            queue[++rear] = root; // push root

            while (front <= rear && node_dibuat < Jml_Node) {
                int current = queue[front++]; // pop

                // nentuin jumlah anak
                int sisa = Jml_Node - node_dibuat;
                int num_anak = (sisa > 0) ? (rand() % 3 + 1) : 0;
                if (num_anak > sisa) {
                    num_anak = sisa;
                }
                
                if (num_anak > 0) {
                    int first_child = node_dibuat + 1;
                    X[current].ps_fs = first_child;
                }

                int i = 0;
                while (i < num_anak) {
                    int child_idx = node_dibuat + 1;
                    X[child_idx].info = 'A' + node_dibuat;
                    X[child_idx].ps_pr = current;
                    X[child_idx].ps_nb = (i < num_anak - 1) ? child_idx + 1 : 0;
                    X[child_idx].ps_fs = 0;
                    queue[++rear] = child_idx;
                    node_dibuat++;
                    i++;
                }
            }
        }
    } else {
        printf("Jumlah Node tidak valid");
    }
}

#include "nbtrees.h"
#include <stdio.h>

/* ***** Status Pohon ***** */
boolean IsEmpty(Isi_Tree P) {
    /* Mengembalikan true jika Isi_Tree kosong */
    return (P[1].info == '\0' || P[1].ps_fs == nil);
}

/* ***** Traversal Pohon Non Biner ***** */
void PreOrder(Isi_Tree P) {
    /* Traversal PreOrder: Parent, fs, nb */
    if (!IsEmpty(P)) {
        int stack[jml_maks + 1];
        int top = -1;
        stack[++top] = 1; // Push root

        while (top >= 0) {
            int idx = stack[top--]; // Pop
            if (idx != nil && P[idx].info != '\0') {
                printf("%c ", P[idx].info); // Cetak parent
                
                // Push nb dan fs dalam urutan terbalik (nb diproses setelah fs)
                if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') {
                    stack[++top] = P[idx].ps_nb;
                }
                if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') {
                    stack[++top] = P[idx].ps_fs;
                }
            }
        }
    }
}

void InOrder(Isi_Tree P) {
    /* Traversal InOrder: fs, Parent, sisa anak lain */
    if (!IsEmpty(P)) {
        int stack[jml_maks + 1];
        int top = -1;
        int idx = 1;
        
        while (top >= 0 || (idx != nil && P[idx].info != '\0')) {
            // Push semua fs ke stack
            while (idx != nil && P[idx].info != '\0') {
                stack[++top] = idx;
                idx = P[idx].ps_fs;
            }
            
            if (top >= 0) {
                idx = stack[top--]; // Pop
                printf("%c ", P[idx].info); // Cetak parent
                idx = P[idx].ps_nb; // Lanjut ke nb
            }
        }
    }
}

void PostOrder(Isi_Tree P) {
    /* Traversal PostOrder: fs, nb, Parent */
    if (!IsEmpty(P)) {
        int stack[jml_maks + 1];
        int top = -1;
        int idx = 1;
        int lastVisited = nil;
        
        while (top >= 0 || (idx != nil && P[idx].info != '\0')) {
            // Push semua fs ke stack
            while (idx != nil && P[idx].info != '\0') {
                stack[++top] = idx;
                idx = P[idx].ps_fs;
            }
            
            if (top >= 0) {
                idx = stack[top]; // Peek
                if (P[idx].ps_nb == nil || P[idx].ps_nb == lastVisited) {
                    printf("%c ", P[idx].info); // Cetak parent
                    lastVisited = idx;
                    top--; // Pop
                    idx = nil;
                } else {
                    idx = P[idx].ps_nb; // Lanjut ke nb
                }
            }
        }
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    /* Traversal Level Order */
    if (IsEmpty(X)) {
        return;
    }

    int queue[jml_maks + 1];
    int front = 0, rear = -1;
    queue[++rear] = 1; // Enqueue root

    while (front <= rear) {
        int current = queue[front++]; // Dequeue
        if (current <= Maks_node && X[current].info != '\0') {
            printf("%c ", X[current].info); // Cetak node

            // Enqueue anak-anak (fs dan nb)
            int child = X[current].ps_fs;
            while (child != nil && child <= Maks_node) {
                if (X[child].info != '\0') {
                    queue[++rear] = child;
                }
                child = X[child].ps_nb;
            }
        }
    }
}

void PrintTree(Isi_Tree P) {
    /* Menampilkan struktur tree dengan indentasi */
    if (IsEmpty(P)) {
        printf("Tree kosong\n");
        return;
    }

    int stack[jml_maks + 1];
    int level[jml_maks + 1];
    int top = -1;
    stack[++top] = 1; // Push root
    level[top] = 0;   // Level root = 0

    while (top >= 0) {
        int idx = stack[top]; // Pop
        int lvl = level[top--];

        if (idx != nil && P[idx].info != '\0') {
            // Cetak indentasi
            for (int i = 0; i < lvl; i++) {
                printf("  ");
            }
            printf("%c\n", P[idx].info); // Cetak node

            // Push semua anak (fs dan nb) dalam urutan terbalik
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

/* ***** Search ***** */
boolean Search(Isi_Tree P, infotype X) {
    /* Mengembalikan true jika ada node dengan nilai X */
    if (IsEmpty(P)) {
        return false;
    }

    int stack[jml_maks + 1];
    int top = -1;
    stack[++top] = 1; // Push root

    while (top >= 0) {
        int idx = stack[top--]; // Pop
        if (idx != nil && P[idx].info != '\0') {
            if (P[idx].info == X) {
                return true; // Node ditemukan
            }
            // Push nb dan fs
            if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') {
                stack[++top] = P[idx].ps_nb;
            }
            if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') {
                stack[++top] = P[idx].ps_fs;
            }
        }
    }
    return false;
}

/* ***** Fungsi Lain ***** */
int nbElmt(Isi_Tree P) {
    /* Mengembalikan jumlah elemen (node) di pohon */
    if (IsEmpty(P)) {
        return 0;
    }

    int count = 0;
    int stack[jml_maks + 1];
    int top = -1;
    stack[++top] = 1; // Push root

    while (top >= 0) {
        int idx = stack[top--]; // Pop
        if (idx != nil && P[idx].info != '\0') {
            count++; // Hitung node
            // Push nb dan fs
            if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') {
                stack[++top] = P[idx].ps_nb;
            }
            if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') {
                stack[++top] = P[idx].ps_fs;
            }
        }
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    /* Mengembalikan jumlah daun (node tanpa anak) di pohon */
    if (IsEmpty(P)) {
        return 0;
    }

    int count = 0;
    int stack[jml_maks + 1];
    int top = -1;
    stack[++top] = 1; // Push root

    while (top >= 0) {
        int idx = stack[top--]; // Pop
        if (idx != nil && P[idx].info != '\0') {
            if (P[idx].ps_fs == nil) {
                count++; // Node adalah daun
            }
            // Push nb dan fs
            if (P[idx].ps_nb != nil && P[P[idx].ps_nb].info != '\0') {
                stack[++top] = P[idx].ps_nb;
            }
            if (P[idx].ps_fs != nil && P[P[idx].ps_fs].info != '\0') {
                stack[++top] = P[idx].ps_fs;
            }
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    /* Mengembalikan level node X, akar level 0 */
    if (IsEmpty(P)) {
        return -1;
    }

    int queue[jml_maks + 1];
    int levels[jml_maks + 1];
    int front = 0, rear = -1;
    queue[++rear] = 1; // Enqueue root
    levels[rear] = 0;  // Level root = 0

    while (front <= rear) {
        int idx = queue[front]; // Dequeue
        int lvl = levels[front++];

        if (idx != nil && P[idx].info != '\0') {
            if (P[idx].info == X) {
                return lvl; // Node ditemukan
            }
            // Enqueue anak-anak
            int child = P[idx].ps_fs;
            while (child != nil && P[child].info != '\0') {
                queue[++rear] = child;
                levels[rear] = lvl + 1;
                child = P[child].ps_nb;
            }
        }
    }
    return -1; // Tidak ditemukan
}

int Depth(Isi_Tree P) {
    /* Mengembalikan kedalaman (tinggi) pohon */
    if (IsEmpty(P)) {
        return 0;
    }

    int queue[jml_maks + 1];
    int levels[jml_maks + 1];
    int front = 0, rear = -1;
    queue[++rear] = 1; // Enqueue root
    levels[rear] = 0;  // Level root = 0
    int maxDepth = 0;

    while (front <= rear) {
        int idx = queue[front]; // Dequeue
        int lvl = levels[front++];

        if (idx != nil && P[idx].info != '\0') {
            if (lvl > maxDepth) {
                maxDepth = lvl; // Update kedalaman maksimum
            }
            // Enqueue anak-anak
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

int Max(infotype Data1, infotype Data2) {
    /* Mengembalikan nilai terbesar dari dua infotype */
    return (Data1 > Data2) ? Data1 : Data2;
}