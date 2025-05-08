#include "nbtrees.h"
#include "nbtress.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Isi_Tree T;
    int Jml_Node;

    // Input jumlah node
    printf("Masukkan jumlah node (0-%d): ", jml_maks);
    scanf("%d", &Jml_Node);

    // Buat pohon
    Create_Tree(T, Jml_Node);

    // Uji fungsi IsEmpty
    printf("\n=== Status Pohon ===\n");
    printf("IsEmpty: %d\n", IsEmpty(T));

    // Uji traversal
    printf("\n=== Traversal ===\n");
    printf("PreOrder: ");
    PreOrder(T);
    printf("\nInOrder: ");
    InOrder(T);
    printf("\nPostOrder: ");
    PostOrder(T);
    printf("\nLevel_order: ");
    Level_order(T, jml_maks);
    printf("\n");

    // Uji PrintTree
    printf("\n=== Struktur Pohon ===\n");
    PrintTree(T);

    // Uji Search
    printf("\n=== Pencarian ===\n");
    char search_char = 'B';
    printf("Search '%c': %d\n", search_char, Search(T, search_char));

    // Uji fungsi lain
    printf("\n=== Properti Pohon ===\n");
    printf("Jumlah node: %d\n", nbElmt(T));
    printf("Jumlah daun: %d\n", nbDaun(T));
    printf("Level '%c': %d\n", search_char, Level(T, search_char));
    printf("Kedalaman: %d\n", Depth(T));

    // Uji Max
    printf("\n=== Utilitas ===\n");
    char c1 = 'A', c2 = 'B';
    printf("Max('%c', '%c'): %c\n", c1, c2, Max(c1, c2));

    return 0;
}