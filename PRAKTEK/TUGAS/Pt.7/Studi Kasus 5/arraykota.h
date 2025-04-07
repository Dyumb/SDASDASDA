#ifndef ARRAYKOTA_H
#define ARRAYKOTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"

#define MAX_KOTA 5

typedef struct {
    Element elements[MAX_KOTA];
    int count;
} ArrayNRLL;

void InitArray(ArrayNRLL* array);
int AddElementToArray(ArrayNRLL* array, char* kt);
void DeleteElement(ArrayNRLL* array, char* kt);
int CountElements(ArrayNRLL* array);
void InsertName(ArrayNRLL* array, char* kt, char* nm);
void DeleteName(ArrayNRLL* array, char* kt, char* nm);
void PrintStructure(ArrayNRLL* array);
int CountTotalNames(ArrayNRLL* array);

#endif // ARRAYKOTA_H