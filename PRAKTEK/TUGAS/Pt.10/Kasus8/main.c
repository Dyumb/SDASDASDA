
#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"
#include "create_tree.c"
#include "tree_status.c"
#include "tree_properties.c"
#include "tree_traversal.c"

int main() {
    Isi_Tree tree;
    int pilihan, jumlah;
    char cari;

    do {
        printf("\n======= MENU POHON NON-BINER =======\n");
        printf("1. Buat Pohon\n");
        printf("2. Tampilkan Traversal Preorder\n");
        printf("3. Tampilkan Traversal Inorder\n");
        printf("4. Tampilkan Traversal Postorder\n");
        printf("5. Tampilkan Traversal Level Order\n");
        printf("6. Tampilkan Struktur Pohon\n");
        printf("7. Cari Elemen\n");
        printf("8. Hitung Jumlah Simpul\n");
        printf("9. Hitung Jumlah Daun\n");
        printf("10. Cari Level Simpul\n");
        printf("11. Hitung Kedalaman Pohon\n");
        printf("12. Tampilkan Detail Setiap Node\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan jumlah simpul (maks %d): ", jml_maks);
                scanf("%d", &jumlah);
                Create_Tree(tree, jumlah);
                break;
            case 2:
                printf("Traversal Preorder: ");
                PreOrder(tree);
                printf("\n");
                break;
            case 3:
                printf("Traversal Inorder: ");
                InOrder(tree);
                printf("\n");
                break;
            case 4:
                printf("Traversal Postorder: ");
                PostOrder(tree);
                printf("\n");
                break;
            case 5:
                printf("Traversal Level Order: ");
                Level_order(tree, jml_maks);
                printf("\n");
                break;
            case 6:
                printf("Struktur Pohon:\n");
                PrintTree(tree);
                break;
            case 7:
                printf("Masukkan elemen yang dicari: ");
                scanf(" %c", &cari);
                if (Search(tree, cari))
                    printf("Elemen '%c' ditemukan di pohon.\n", cari);
                else
                    printf("Elemen '%c' tidak ditemukan.\n", cari);
                break;
            case 8:
                printf("Jumlah simpul: %d\n", nbElmt(tree));
                break;
            case 9:
                printf("Jumlah daun: %d\n", nbDaun(tree));
                break;
            case 10:
                printf("Masukkan elemen: ");
                scanf(" %c", &cari);
                printf("Level elemen '%c' = %d\n", cari, Level(tree, cari));
                break;
            case 11:
                printf("Kedalaman pohon: %d\n", Depth(tree));
                break;
            case 12:
                PrintNodeDetail(tree);
                break;
            case 0:
                printf("Terima kasih! Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
