#include <stdio.h>
#include <stdlib.h>

/* Kamus Global */
int N; /* ukuran efektif */
enum MyType { bulat, karakter };

/* Prototype fungsi yang diberikan sebagai parameter */
void succI(int *i);  /* Suksessor integer */
void predI(int *i);  /* Predesessor integer */
void succC(char *c);  /* Suksessor karakter */
void predC(char *c);  /* Predesessor karakter */

/* Print tabel dengan tipe yang belum diketahui */
void printtab(void *T, enum MyType Ty);

/* Prosedur geser elemen tabel dengan fungsi parameter */
void geser(void *TT, void (*f)(void *), enum MyType Ty);

int main() {
    /* Kamus Lokal */
    int *MyTabInt;
    char *MyTabC;
    int i;

    /* Alokasi memori */
    N = 10;
    MyTabInt = (int *)malloc(N * sizeof(int));
    MyTabC = (char *)malloc(N * sizeof(char));

    /* Inisialisasi array */
    for (i = 0; i < N; i++) {
        MyTabInt[i] = i;
        MyTabC[i] = 'Z' - i;
    }

    /* Cetak tabel sebelum pemanggilan geser() */
    printf("Isi tabel sebelum pemanggilan geser():\n");
    printf(" Tabel integer: ");
    printtab(MyTabInt, bulat);
    printf(" Tabel karakter: ");
    printtab(MyTabC, karakter);
    printf("\n");

    /* Geser dengan fungsi succ */
    printf("Geser dengan succ:\n");
    geser(MyTabInt, (void *)succI, bulat);
    geser(MyTabC, (void *)succC, karakter);
    printf(" Tabel integer setelah geser: ");
    printtab(MyTabInt, bulat);
    printf(" Tabel karakter setelah geser: ");
    printtab(MyTabC, karakter);
    printf("\n");

    /* Geser dengan fungsi pred */
    printf("Geser dengan pred:\n");
    geser(MyTabInt, (void *)predI, bulat);
    geser(MyTabC, (void *)predC, karakter);
    printf(" Tabel integer setelah geser kembali: ");
    printtab(MyTabInt, bulat);
    printf(" Tabel karakter setelah geser kembali: ");
    printtab(MyTabC, karakter);
    printf("\n");

    /* Dealokasi memori */
    free(MyTabInt);
    free(MyTabC);

    return 0;
}

/* Implementasi fungsi operasi */
void succI(int *i) { *i = *i + 1; }
void predI(int *i) { *i = *i - 1; }
void succC(char *c) { *c = *c + 1; }
void predC(char *c) { *c = *c - 1; }

/* Implementasi prosedur geser */
void geser(void *TT, void (*f)(void *), enum MyType Ty) {
    int i;
    printf(" Dalam geser: ");
    if (Ty == bulat) {
        int *arr = (int *)TT;
        for (i = 0; i < N; i++) {
            f(&arr[i]);
            printf("%d ", arr[i]);
        }
    } else {
        char *arr = (char *)TT;
        for (i = 0; i < N; i++) {
            f(&arr[i]);
            printf("%c ", arr[i]);
        }
    }
    printf("\n");
}

/* Implementasi printtab */
void printtab(void *T, enum MyType Ty) {
    int i;
    if (Ty == bulat) {
        int *arr = (int *)T;
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        char *arr = (char *)T;
        for (i = 0; i < N; i++) {
            printf("%c ", arr[i]);
        }
    }
    printf("\n");
}
