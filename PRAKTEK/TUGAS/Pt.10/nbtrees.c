#include <stdio.h>
#include "nbtrees.h"

// Fungsi bantu untuk traversal InOrder dari node tertentu
void InOrderHelper(Isi_Tree P, int current) {
    if (current == nil || current < 1 || current > jml_maks || P[current].info == '\0') {
        return; // Berhenti jika indeks tidak valid atau node kosong
    }

    // Telusuri subtree dari first child (ps_fs)
    if (P[current].ps_fs != nil) {
        InOrderHelper(P, P[current].ps_fs);
    }

    // Cetak node saat ini
    printf("%c ", P[current].info);

    // Telusuri semua saudara (ps_nb)
    if (P[current].ps_nb != nil) {
        InOrderHelper(P, P[current].ps_nb);
    }
}

void Create_tree(Isi_Tree X, int Jml_Node) {
    if (Jml_Node > jml_maks) Jml_Node = jml_maks;

    X[1].info = '#'; X[1].ps_fs = 2; X[1].ps_nb = 3; X[1].ps_pr = nil;
    X[2].info = 'C'; X[2].ps_fs = 4; X[2].ps_nb = 5; X[2].ps_pr = 1;
    X[3].info = 'F'; X[3].ps_fs = 6; X[3].ps_nb = 7; X[3].ps_pr = 1;
    X[4].info = 'E'; X[4].ps_fs = 8; X[4].ps_nb = 9; X[4].ps_pr = 2;
    X[5].info = 'H'; X[5].ps_fs = 10; X[5].ps_nb = 11; X[5].ps_pr = 2;
    X[6].info = 'B'; X[6].ps_fs = 12; X[6].ps_nb = 7; X[6].ps_pr = 3;
    X[7].info = 'N'; X[7].ps_fs = 14; X[7].ps_nb = 15; X[7].ps_pr = 3;
    X[8].info = 'K'; X[8].ps_fs = 16; X[8].ps_nb = 17; X[8].ps_pr = 4;
    X[9].info = 'R'; X[9].ps_fs = 18; X[9].ps_nb = 19; X[9].ps_pr = 4;
    X[10].info = 'A'; X[10].ps_fs = 20; X[10].ps_nb = 21; X[10].ps_pr = 5;
    X[11].info = 'D'; X[11].ps_fs = 22; X[11].ps_nb = 23; X[11].ps_pr = 5;
    X[12].info = 'J'; X[12].ps_fs = 24; X[12].ps_nb = 25; X[12].ps_pr = 6;
    X[13].info = 'V'; X[13].ps_fs = 26; X[13].ps_nb = 27; X[13].ps_pr = 6;
    X[14].info = 'G'; X[14].ps_fs = 28; X[14].ps_nb = 29; X[14].ps_pr = 7;
    X[15].info = 'M'; X[15].ps_fs = 30; X[15].ps_nb = 31; X[15].ps_pr = 7;
    X[16].info = 'U'; X[16].ps_fs = 32; X[16].ps_nb = 33; X[16].ps_pr = 8;
    X[17].info = 'Q'; X[17].ps_fs = 34; X[17].ps_nb = 35; X[17].ps_pr = 8;
    X[18].info = '1'; X[18].ps_fs = 36; X[18].ps_nb = 37; X[18].ps_pr = 9;
    X[19].info = 'W'; X[19].ps_fs = 38; X[19].ps_nb = nil; X[19].ps_pr = 9;
    X[20].info = '3'; X[20].ps_fs = 36; X[20].ps_nb = 37; X[20].ps_pr = 10;
    X[21].info = 'Z'; X[21].ps_fs = nil; X[21].ps_nb = nil; X[21].ps_pr = 10;
    X[22].info = 'L'; X[22].ps_fs = nil; X[22].ps_nb = nil; X[22].ps_pr = 11;
    X[23].info = 'O'; X[23].ps_fs = nil; X[23].ps_nb = nil; X[23].ps_pr = 11;
    X[24].info = 'P'; X[24].ps_fs = nil; X[24].ps_nb = nil; X[24].ps_pr = 12;
    X[25].info = 'T'; X[25].ps_fs = nil; X[25].ps_nb = nil; X[25].ps_pr = 12;
    X[26].info = '4'; X[26].ps_fs = nil; X[26].ps_nb = nil; X[26].ps_pr = 13;
    X[27].info = 'X'; X[27].ps_fs = nil; X[27].ps_nb = nil; X[27].ps_pr = 13;
    X[28].info = '7'; X[28].ps_fs = nil; X[28].ps_nb = nil; X[28].ps_pr = 14;
    X[29].info = 'Y'; X[29].ps_fs = nil; X[29].ps_nb = nil; X[29].ps_pr = 14;
    X[30].info = 'I'; X[30].ps_fs = nil; X[30].ps_nb = nil; X[30].ps_pr = 15;
    X[31].info = 'S'; X[31].ps_fs = nil; X[31].ps_nb = nil; X[31].ps_pr = 15;
    X[32].info = '2'; X[32].ps_fs = nil; X[32].ps_nb = nil; X[32].ps_pr = 16;
    X[33].info = '8'; X[33].ps_fs = nil; X[33].ps_nb = nil; X[33].ps_pr = 16;
    X[34].info = '9'; X[34].ps_fs = nil; X[34].ps_nb = nil; X[34].ps_pr = 17;
    X[35].info = '0'; X[35].ps_fs = nil; X[35].ps_nb = nil; X[35].ps_pr = 17;
    X[36].info = '5'; X[36].ps_fs = nil; X[36].ps_nb = nil; X[36].ps_pr = 18;
    X[37].info = ' '; X[37].ps_fs = nil; X[37].ps_nb = nil; X[37].ps_pr = 18;
    X[38].info = '6'; X[38].ps_fs = nil; X[38].ps_nb = nil; X[38].ps_pr = 19;

    for (int i = 39; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

boolean IsEmpty(Isi_Tree P) {
    return P[1].info == '\0';
}

void PreOrder(Isi_Tree P) {
    if (P[1].info != '\0') {
        printf("%c ", P[1].info);
        if (P[1].ps_fs != nil) PreOrder(P + P[1].ps_fs);
        if (P[1].ps_nb != nil) PreOrder(P + P[1].ps_nb);
    }
}

void InOrder(Isi_Tree P) {
    if (IsEmpty(P)) {
        return;
    }
    InOrderHelper(P, 1); // Mulai dari root
}

void PostOrder(Isi_Tree P) {
    if (P[1].info != '\0') {
        if (P[1].ps_fs != nil) PostOrder(P + P[1].ps_fs);
        if (P[1].ps_nb != nil) PostOrder(P + P[1].ps_nb);
        printf("%c ", P[1].info);
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node && X[i].info != '\0'; i++) {
        printf("%c ", X[i].info);
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    Level_order(P, jml_maks);
}

boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks && P[i].info != '\0'; i++) {
        if (P[i].info == X || (X == ' ' && P[i].info == ' ')) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks && P[i].info != '\0'; i++) {
        count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks && P[i].info != '\0'; i++) {
        if (P[i].ps_fs == nil && P[i].ps_nb == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int level = 0;
    int current = 1;
    while (current != nil) {
        if (P[current].info == X || (X == ' ' && P[current].info == ' ')) return level;
        if (P[current].ps_fs != nil && Search(P + P[current].ps_fs, X)) {
            current = P[current].ps_fs;
        } else if (P[current].ps_nb != nil && Search(P + P[current].ps_nb, X)) {
            current = P[current].ps_nb;
        } else {
            break;
        }
        level++;
    }
    return -1;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    int leftDepth = 0, rightDepth = 0;
    if (P[1].ps_fs != nil) leftDepth = Depth(P + P[1].ps_fs);
    if (P[1].ps_nb != nil) rightDepth = Depth(P + P[1].ps_nb);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int Max(infotype Data1, infotype Data2) {
    return Data1 > Data2 ? Data1 : Data2;
}