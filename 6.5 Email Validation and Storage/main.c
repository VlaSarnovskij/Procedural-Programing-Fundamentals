#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 256

int main() {
    char buffer[CAPACITY];

    printf("Programme will check if the email address entered correctly.\n");

    while (1) {
        printf("Enter email address: ");
        scanf("%s", buffer);

        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        int at_pos = -1;   // Position of '@'
        int dot_pos = -1;  // Position of '.' after '@'
        int i = 0;
        int valid = 1;     // Flag for valid email

        // Find the length manually and scan for '@' and '.' after '@'
        while (buffer[i] != '\0') {
            if (buffer[i] == '@') {
                if (at_pos != -1) { // More than one '@'
                    valid = 0;
                    break;
                }
                at_pos = i;
            } else if (buffer[i] == '.' && at_pos != -1 && dot_pos == -1) {
                dot_pos = i;
            }
            i++;
        }

        // Check validity conditions
        if (at_pos <= 0) valid = 0;            // At least one char before '@'
        if (dot_pos <= at_pos + 1) valid = 0;  // At least one char between '@' and '.'
        if (dot_pos == -1 || buffer[dot_pos + 1] == '\0') valid = 0; // At least one char after '.'

        if (valid) {
            printf("Email is correct.\n");

            // Print the domain (part after '@')
            printf("Domain: ");
            int j = at_pos + 1;
            while (buffer[j] != '\0') {
                putchar(buffer[j]);
                j++;
            }
            putchar('\n');

            // Append the email to the file "emails.txt"
            FILE *fp = fopen("emails.txt", "a"); // append mode
            fprintf(fp, "%s\n", buffer);
            fclose(fp);
            break;
        } else {
            printf("Error: incorrect email. Try again.\n");
        }
    }
    return 0;
}
