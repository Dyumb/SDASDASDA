#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nama[25];
    struct Node* q;
} Node;

typedef struct CityNode {
    char kota[25];
    Node* p;
    struct CityNode* next;
} CityNode;

Node* CreateNode(char* nm);
void InsertNode(Node** list, char* nm);
void DeleteNode(Node** list, char* nm);
int CountNodes(Node* list);
void PrintList(Node* list);

CityNode* CreateCityNode(char* kt);
void InsertCity(CityNode** list, char* kt);
void DeleteCity(CityNode** list, char* kt);
int CountCities(CityNode* list);

#endif