#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "morse_utils.h"
#include "nbtrees.h"

// Fungsi bantu untuk traversal dan mencatat kode
boolean traverseEncode(Isi_Tree P, int current, infotype X, char *temp, int *len) {
    if (current == nil || P[current].info == '\0') return false;

    // Cek apakah node saat ini adalah target
    if (P[current].info == X || (X == ' ' && P[current].info == ' ')) {
        temp[*len] = '\0';
        return true;
    }

    // Coba ke anak pertama (ps_fs) sebagai '!'
    if (P[current].ps_fs != nil) {
        temp[*len] = '!';
        (*len)++;
        if (traverseEncode(P, P[current].ps_fs, X, temp, len)) return true;
        (*len)--; // Backtrack
    }

    // Coba ke saudara berikutnya (ps_nb) sebagai '?'
    if (P[current].ps_nb != nil) {
        temp[*len] = '?';
        (*len)++;
        if (traverseEncode(P, P[current].ps_nb, X, temp, len)) return true;
        (*len)--; // Backtrack
    }

    return false;
}

void encodeChar(Isi_Tree P, infotype X, char *result) {
    result[0] = '\0'; // Kosongkan result jika tidak ditemukan
    X = (char)toupper((unsigned char)X); // Cast untuk menghindari warning

    char temp[20] = "";
    int len = 0;
    if (traverseEncode(P, 1, X, temp, &len)) {
        strcpy(result, temp);
    } else {
        // Jika tidak ditemukan, kosongkan result
        result[0] = '\0';
    }
}

void encodeString(Isi_Tree P, char *str, char *result) {
    result[0] = '\0';
    char temp[20];
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        encodeChar(P, str[i], temp);
        if (temp[0] != '\0') {
            strcat(result, temp);
            if (str[i + 1] != '\0') strcat(result, " "); // Tambah spasi hanya jika bukan karakter terakhir
            len += strlen(temp) + (str[i + 1] != '\0' ? 1 : 0);
        }
    }
    if (len > 0 && result[len - 1] == ' ') result[len - 1] = '\0'; // Hapus spasi terakhir
}

void decodeCode(Isi_Tree P, char *code, infotype *result) {
    *result = '\0'; // Kosongkan jika tidak ditemukan
    int current = 1; // Mulai dari root

    for (int i = 0; code[i] != '\0'; i++) {
        if (current == nil || P[current].info == '\0') return;

        if (code[i] == '!') {
            current = (P[current].ps_fs != nil) ? P[current].ps_fs : nil;
        } else if (code[i] == '?') {
            current = (P[current].ps_nb != nil) ? P[current].ps_nb : nil;
        }
    }

    if (current != nil && P[current].info != '\0') {
        *result = P[current].info;
        if (*result == ' ') *result = ' ';
    }
}

void readFileAndConvert(Isi_Tree P, char *inputFile, char *outputFile) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");
    if (fin == NULL || fout == NULL) return;

    char line[100];
    while (fgets(line, sizeof(line), fin)) {
        line[strcspn(line, "\n")] = 0;
        char encoded[200] = "";
        encodeString(P, line, encoded);
        fprintf(fout, "%s\n", encoded);
    }

    fclose(fin);
    fclose(fout);
}