#include <stdio.h>
#include <stdlib.h>

#define LENGTH_AFTER_COMMA_MAX 3
#define CAPACITY 256

void get_filename (char *filename){
    printf("Please enter file name and its extension(exp. in.txt): \n\n");
    scanf("%s", filename);
}

int main()
{
    char filename[CAPACITY] = "in.txt";   // File name
    char buffer[CAPACITY];                // Keeps files body
    double number;                        // Number in file
    FILE *fp;                             // Pointer on file

    printf("Programme to print the length of the entered number.\n");

    while(1){
        // Open file
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: unable to open the file.\n");
            get_filename(filename);
            continue;
        }
        printf("Number scanned from %s : ", filename);

        // Reading file
        while(1){
            if(fscanf(fp, "%255s", buffer) != 1){
                break;
            }
            printf(buffer);
        }
        printf("\n");
        fclose(fp);

        int length = 0;
        int length_after_comma = 0;
        int found = 0; // comma was found?
        // Switching ',' into '.' to convert symbols into number
        while (buffer[length] != '\0') {
            if (buffer[length] == ',') {
                buffer[length] = '.';
                found = 1;
            } else if(found){
                ++length_after_comma;
            }
            ++length;
        }

        // Konvertation
        number = atof(buffer);

        // Check numbers for all conditions
        if (number >= 10 && number <= 1000) {
            if (length_after_comma <= LENGTH_AFTER_COMMA_MAX){
               printf("Length of the number entered: %d\n", length);
                break;
            }
            printf("Error: the value must have no more than 3 digits after the decimal point.\n");
        } else {
            printf("Error: the number must be between 10 and 1000.\n");
        }
        get_filename(filename);
        continue;
    }
    return 0;
}
