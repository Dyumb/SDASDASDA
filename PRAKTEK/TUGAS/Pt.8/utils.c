#include <stdio.h>
#include <string.h>
#include "utils.h"

void safeInput(char *buffer, int size) {
    fgets(buffer, size, stdin);
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}