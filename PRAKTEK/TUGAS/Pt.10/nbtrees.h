#ifndef NBTREES_H
#define NBTREES_H

#define jml_maks 63
#define nil -1

#include "boolean.h"

typedef char infotype;
typedef struct {
    infotype info;
    int ps_fs; // first child
    int ps_nb; // next brother
    int ps_pr; // parent
} ElmtTree;

typedef ElmtTree Isi_Tree[jml_maks + 1];

void InOrderHelper(Isi_Tree P, int current);
void Create_tree(Isi_Tree X, int Jml_Node);
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

#endif // NBTREES_H