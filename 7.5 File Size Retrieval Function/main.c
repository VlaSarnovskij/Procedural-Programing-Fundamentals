#include <stdio.h>
#include <stdlib.h>

long getFileSize(char *fileName){
    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        printf("Nepavyko atidaryti failo!\n");
        return -1; // Klaidos atveju
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file); // Uzdarom faila

    return size;
}


int main()
{
    char filename[] = "size.txt";

    long fileSize = getFileSize(filename);

    printf("Files %s size is %ld bytes", filename, fileSize);

    return 0;
}
