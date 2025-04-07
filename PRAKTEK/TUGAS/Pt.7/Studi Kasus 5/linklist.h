#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nama[25];
    struct Node* q;
} Node;

typedef struct {
    char kota[25];
    Node* p;
} Element;

Node* CreateNode(char* nm);
void InsertNode(Node** list, char* nm);
void DeleteNode(Node** list, char* nm);
int CountNodes(Node* list);
void PrintList(Node* list);

Element CreateElement(char* kt);
void LinkToList(Element* element, Node* list);

#endif // LINKLIST_H