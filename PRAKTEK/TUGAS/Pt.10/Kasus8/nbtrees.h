
#ifndef NBTREES_H
#define NBTREES_H

#include "boolean.h"

#define jml_maks 20
#define nil 0
typedef char infotype;
typedef int address;
typedef struct { infotype info; address ps_fs, ps_nb, ps_pr; } nbtree;
typedef nbtree Isi_Tree[jml_maks+1];

void Create_Tree(Isi_Tree X, int Jml_Node);
boolean IsEmpty(Isi_Tree P);
void PreOrder(Isi_Tree P);
void InOrder(Isi_Tree P);
void PostOrder(Isi_Tree P);
void Level_order(Isi_Tree X, int Maks_node);
void PrintTree(Isi_Tree P);
boolean Search(Isi_Tree P, infotype X);
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);
int Max(infotype Data1, infotype Data2);
void PrintNodeDetail(Isi_Tree T);

#endif
