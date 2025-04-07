/* ----------------------------------------------------------------------------- */
/* File : PTR11.cpp */
/* Deskripsi : Pointer ke function (Function sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ----------------------------------------------------------------------------- */

/* Kamus Global */
int N; /* ukuran efektif */

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
int succ (int i); /* succ -> singkatan dari suksessor */
int pred (int i); /* pred -> singkatan dari predesessor */

/* Prosedur dengan parameter sebuah fungsi */
void geser (int *TT, int (*f) (int));

/* Program Utama */
int main()
{
    /* kamus lokal */
    int MyTab[10]; // deklarasi var. MyTab berupa array dengan 10 elemen
    int i; // deklarasi var. i

    /* program */
    N = 10;
    for (i = 0; i < N; i++)
    {
    MyTab[i] = i;
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    for (i = 0; i < N; i++)
    {
    printf(" %d ", MyTab[i]);
    }
    printf("\n");

    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n");
    geser (MyTab, succ); // pemanggilan modul geser
    printf(" dalam main setelah aplikasi succ \n");
    for (i = 0; i < N; i++)
    {
    printf(" %d ", MyTab[i]);
    }
    printf("\n\n");

    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n");
    geser (MyTab, pred); // pemanggilan modul geser
    printf(" dalam main setelah aplikasi pred \n");
    for (i = 0; i < N; i++)
    {
    printf(" %d ", MyTab[i]);
    }
    printf("\n");
    return 0;
    }

    /* Body Function */
    int succ (int i) // isi dari modul succ
    {
    return (i+1);
    }

    int pred (int i) // isi dari modul pred
    {
    return (i-1);
    }

    void geser (int *TT, int (*f) (int)) // isi dari modul geser
                                         // parameternya *TT untuk array MyTab, *f untuk fungsi yang dipanggil
    {
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++)
    {
    TT[i] = f (TT[i]); // untuk tiap index array TT, akan dilakukan fungsi yang dipanggil oleh modul geser ke f
    printf(" %d ", TT[i]);
    }
    printf("\n");
}
