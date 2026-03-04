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

char* findMaxFileSize(int argc, char* argv[]){
    if (argc <= 1) return NULL; // no files

    char* maxFileSizeName = argv[1];
    long maxSize = getFileSize(argv[1]);
    for(int i = 2; i < argc; ++i){
        if(getFileSize(argv[i]) > maxSize){
            maxSize = getFileSize(argv[i]);
            maxFileSizeName = argv[i];
        }
    }
    return maxFileSizeName;
}

int main(int argc, char* argv[])
{
    char* filename = findMaxFileSize(argc, argv);
    if (filename == NULL){
        printf("There is no files.");
        return 1;
    }

    printf("File %s is the largest.", filename);
    return 0;
}
