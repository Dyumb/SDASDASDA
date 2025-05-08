#ifndef SLL_MODE_H
#define SLL_MODE_H

void tambahBukuSLL(char judul[], int stok);
void tampilBukuSLL();
void pinjamBukuSLL(char nama[], int prioritas, char judul[]);
void kembalikanBukuSLL(char judul[]);
void batalkanPeminjamanSLL(char judul[], char nama[]);
void bebaskanBukuSLL();

#endif