#ifndef FILE_H		// Include guard	
#define FILE_H

#include <stdio.h>

void saveToFile(const char *filename, int *arr, int size);
int* loadFromFile(const char *filename, int *outSize);

#endif
