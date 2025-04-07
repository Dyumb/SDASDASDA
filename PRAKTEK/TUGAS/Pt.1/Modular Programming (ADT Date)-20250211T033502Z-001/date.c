/* File        : date.c */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include <stdio.h>
#include <math.h>
#include "date.h"

/*********** Operasi Primitif ************/
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
void CreateDate (date * D){
	SetTgl (01, &(* D));
	SetBln (01, &(* D));
	SetThn (1900, &(* D));
}

/******* Selector komponen **********/
/* Mengambil bagian Tgl dari date */
int GetTgl (date D){
	return(D.Tgl);
}

/* Mengambil bagian Bln dari date */
int GetBln (date D){
	return(D.Bln);
}

/* Mengambil bagian Thn dari date */
int GetThn (date D){
	return(D.Thn);
}


/****** Pengubah komponen ******/
/* Memberi nilai untuk Tgl */
void SetTgl (int NewTgl, date * D){
	(* D).Tgl = NewTgl;
}

/* Memberi nilai untuk Bln */
void SetBln (int NewBln, date * D){
	(* D).Bln = NewBln;
}

/* Memberi nilai untuk Thn */
void SetThn (int NewThn, date * D){
	(* D).Thn = NewThn;
}


/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
void ReadDate (date * D){
    printf("Tanggal : ");
    scanf("%d", &D->Tgl);
    printf("Bulan : ");
    scanf("%d", &D->Bln);
    printf("Tahun : ");
    scanf("%d", &D->Thn);
}

/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
boolean isValid(date D){
	if ((GetThn(D) < 1900)||(GetThn(D) > 30000)||(GetBln(D) < 1) ||(GetBln(D) > 12)||(GetTgl(D) < 1)||(GetTgl(D) > getEndDate(D)))
		return (false);
	else
		return (true);
}

/* Print nilai D dengan format dd/mm/yyyy */
void PrintObj (date D){
	printf ("%d/%d/%d\n", GetTgl(D), GetBln(D), GetThn(D));
}

/****** Operator Relasional ******/
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
boolean isKabisat (date D){
    if ((D.Thn % 400 == 0) || (D.Thn % 4 == 0 && D.Thn % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}

/***** Predikat lain *******/
/* Memberikan tanggal terakhir dari sebuah bulan */
int getEndDate (date D){
    int AkhirBulan[12] = {30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(D.Bln == 2 && isKabisat(D) == true){
        AkhirBulan[2] = 29;
    }
    return AkhirBulan[D.Bln - 1];
}

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
void DateBefore (date D){
    int maxHari;
    int tglLama = D.Tgl - 1;
    int blnLama = D.Bln;
    int thnLama = D.Thn;

    if (D.Bln == 1) {
        maxHari = getEndDate((date){.Tgl = 1, .Bln = 12, .Thn = D.Thn - 1});
    } else {
        maxHari = getEndDate((date){.Tgl = 1, .Bln = D.Bln - 1, .Thn = D.Thn});
    }

    if (tglLama == 0) {
        tglLama = maxHari;
        blnLama -= 1;

        if (blnLama == 0) {
            blnLama = 12;
            thnLama -= 1;
        }
    }

    date D4;
    SetTgl(tglLama, &D4);
    SetBln(blnLama, &D4);
    SetThn(thnLama, &D4);

    printf("Menggunakan perintah DateBefore(D), Sebelum tanggal: %d/%d/%d;\n", D.Tgl, D.Bln, D.Thn);
    printf("adalah tanggal: %d/%d/%d\n", D4.Tgl, D4.Bln, D4.Thn);
}


/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
void NextDate(date D) {
    int maxHariSkrg = getEndDate(D);  // Ambil jumlah hari dalam bulan saat ini

    int tglNext = D.Tgl + 1;
    int blnNext = D.Bln;
    int thnNext = D.Thn;

    if (tglNext > maxHariSkrg) {
        tglNext = 1;
        blnNext += 1;

        if (blnNext > 12) {
            blnNext = 1;
            thnNext += 1;
        }
    }

    date D4;
    SetTgl(tglNext, &D4);
    SetBln(blnNext, &D4);
    SetThn(thnNext, &D4);

    printf("Menggunakan perintah NextDate(D), Setelah tanggal: %d/%d/%d;\n", D.Tgl, D.Bln, D.Thn);
    printf("adalah tanggal: %d/%d/%d\n", D4.Tgl, D4.Bln, D4.Thn);
}



/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
void SelisihDate (date D2, date D3){
    int totalHari = 0;

    // Jika D1 lebih besar dari D2, tukar agar D1 selalu lebih kecil
    if (D2.Thn > D3.Thn ||
       (D2.Thn == D3.Thn && D2.Bln > D3.Bln) ||
       (D2.Thn == D3.Thn && D2.Bln == D3.Bln && D2.Tgl > D3.Tgl)) {
        date temp = D2;
        D2 = D3;
        D3 = temp;
    }

    // Hitung jumlah hari dari D1 ke D2 dengan menaikkan tanggal satu per satu
    while (D2.Thn < D3.Thn || D2.Bln < D3.Bln || D2.Tgl < D3.Tgl) {
        D2.Tgl += 1;
        totalHari++;

        if (D2.Tgl > getEndDate(D2)) {
            D2.Tgl = 1;
            D2.Bln += 1;
        }

        if (D2.Bln > 12) {
            D2.Bln = 1;
            D2.Thn += 1;
        }
    }
    printf("Menggunakan perintah SelisihDate(D2, D3) Selisih antara %d/%d/%d\n", D2.Tgl, D2.Bln, D2.Thn);
    printf("dan %d/%d/%d\n", D3.Tgl, D3.Bln, D3.Thn);
    printf("adalah %d hari", totalHari);

}

