#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 256

int main()
{
    char buffer[CAPACITY];
    int num1, num2, num3;
    int average;
    char ch;

    printf("Programme will find average number out of 3 and print it in a file.\n");
    printf("Enter 3 numbers on one line, separate them with ';' symbol.\n");

    // Reading 3 numbers
    while(1){
        scanf("%s", buffer);

        // Clearing input
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (sscanf(buffer, "%d;%d;%d", &num1, &num2, &num3) == 3) {
            break;
        }
        printf("Error: wrong enter format. Try again.\n");
    }

    // Searching for the average number
    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3))
        average = num1;
    else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3))
        average = num2;
    else
        average = num3;


    char filename[CAPACITY];
    do {
        printf("Enter output file name (should end with '.txt'):\n");
        scanf("%s", filename);

        int len = 0;
        while (filename[len] != '\0') len++;

        if (len >= 4 && filename[len-4]=='.' && filename[len-3]=='t' && filename[len-2]=='x' && filename[len-1]=='t') {
            break;
        } else {
            printf("Error: file need to end with '.txt'\n");
        }
    } while (1);

    // Output
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "Average number: %d\n", average);
    fclose(fp);

    printf("Average number (%d) printed in file %s\n", average, filename);
    return 0;
}
