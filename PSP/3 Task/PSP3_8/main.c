#include <stdio.h>
#include <stdlib.h>

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void numToLetter(char *word){
    for (int i = 0; word[i]; i++){
        if (isDigit(word[i])){
            word[i] = word[0];
        }
    }
}

void getWord(char *string) {
    int i = 0;

    // cikle until end of the string
    while (string[i] != '\0' && string[i] != '\n') {
        char word[64];
        int j = 0; // to count word symbols

        // ignore spaces
        while (string[i] == ' ') {
            i++;
        }

        int start = i; // where a word starts

        // collect the word
        while (string[i] != ' ' && string[i] != '\0' && string[i] != '\n') {
            word[j++] = string[i++];
        }

        word[j] = '\0'; // end of the word

        if (j > 0) {
            numToLetter(word); // word conversion function

            // replace old variant of word with converted
            for (int k = 0; k < j; k++) {
                string[start + k] = word[k];
            }
        }
    }
}


int main(int argc, char *argv[])
{
    FILE *file_data = fopen(argv[1], "r");
    if (file_data == NULL) {
        perror("Failed to open an input file.\n");
        return 1;
    }

    FILE *file_results = fopen(argv[2], "a+");
    if (!file_results) {
        perror("Failed to open or creating output file\n");
        fclose(file_data);
        return 1;
    }

    int size = 64;
    char *buffer = malloc(size);

    while (fgets(buffer, size, file_data)) {

        // Checking if the end of the string is '\n'
        int i = 0;
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            i++;
        }

        // If '\n' not the end of a file -> realloc buffer
        while (buffer[i] != '\n' && !feof(file_data)) {

            int oldSize = size;
            size *= 2;
            buffer = realloc(buffer, size);

            // Keep reading file in a buffer
            fgets(buffer + oldSize - 1, size - (oldSize - 1), file_data);

            // Searching for '\n' after reading
            i = oldSize - 1;
            while (buffer[i] != '\0' && buffer[i] != '\n') {
                i++;
            }
        }
        // Convertion of the buffer
        getWord(buffer);
        fprintf(file_results, "%s", buffer);
    }

    free(buffer);

    fclose(file_data);
    fclose(file_results);
    return 0;
}
