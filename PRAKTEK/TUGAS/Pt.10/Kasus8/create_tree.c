
#include "nbtrees.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Create_Tree(Isi_Tree X, int Jml_Node) {
    if (Jml_Node < 0 || Jml_Node > jml_maks) return;

    for (int i = 1; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    if (Jml_Node >= 1) {
        X[1].info = 'A';
        X[1].ps_pr = nil;
        X[1].ps_nb = nil;
        X[1].ps_fs = nil;

        int queue[jml_maks + 1];
        int front = 0, rear = -1;
        int node_dibuat = 1;
        queue[++rear] = 1;

        srand((unsigned int)time(NULL));

        while (front <= rear && node_dibuat < Jml_Node) {
            int current = queue[front++];
            int sisa = Jml_Node - node_dibuat;
            int num_anak = (sisa > 0) ? (rand() % 3 + 1) : 0;
            if (num_anak > sisa) num_anak = sisa;

            if (num_anak > 0) {
                int first_child = node_dibuat + 1;
                X[current].ps_fs = first_child;

                for (int i = 0; i < num_anak; i++) {
                    int child_idx = node_dibuat + 1;
                    X[child_idx].info = (char)('A' + node_dibuat);
                    X[child_idx].ps_pr = current;
                    X[child_idx].ps_nb = (i < num_anak - 1) ? child_idx + 1 : nil;
                    X[child_idx].ps_fs = nil;
                    queue[++rear] = child_idx;
                    node_dibuat++;
                }
            }
        }
    }
}
