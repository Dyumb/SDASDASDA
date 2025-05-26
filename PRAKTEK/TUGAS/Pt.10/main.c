#include <stdio.h>
#include <ctype.h>
#include "nbtrees.h"
#include "morse_utils.h"
#include "nbtrees.c"
#include "morse_utils.c"

int main() {
    Isi_Tree tree;
    Create_tree(tree, 38); // 38 node berdasarkan data yang diberikan
    printf("Pohon dibuat.\n");

    // 2. Menampilkan semua node hasil traversal inorder
    printf("Traversal InOrder: ");
    InOrder(tree);
    printf("\n");

    // 3. Mengonversi string “JTK Politeknik Negeri Bandung” ke kode
    char encodedStr[200];
    encodeString(tree, "JTK Politeknik Negeri Bandung", encodedStr);
    printf("Kode untuk 'JTK Politeknik Negeri Bandung': %s\n", encodedStr);

    // 4. Mengonversi kode contoh (misalnya jalur ke 'B')
    infotype decoded;
    decodeCode(tree, "?!", &decoded); // Uji jalur ke 'B'
    printf("Kode '?!' dikonversi ke: %c\n", decoded);

    // 5. Membaca input.txt, mengonversi, dan menyimpan ke out.txt
    readFileAndConvert(tree, "input.txt", "out.txt");
    printf("Konversi dari input.txt ke out.txt selesai.\n");

    return 0;
}