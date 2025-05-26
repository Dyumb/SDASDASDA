#ifndef MORSE_UTILS_H
#define MORSE_UTILS_H

#include "nbtrees.h"

void encodeChar(Isi_Tree P, infotype X, char *result);
void encodeString(Isi_Tree P, char *str, char *result);
void decodeCode(Isi_Tree P, char *code, infotype *result);
void readFileAndConvert(Isi_Tree P, char *inputFile, char *outputFile);

#endif // MORSE_UTILS_H