#ifndef KOTA_H
#define KOTA_H

#include "linklist.h"

void InsertName(CityNode** list, char* kt, char* nm);
void DeleteName(CityNode** list, char* kt, char* nm);
void DeleteElement(CityNode** list, char* kt);
void PrintStructure(CityNode* list);
int CountTotalNames(CityNode* list);

#endif