#include <stdio.h>
#include <stdlib.h>

// Function to display a menu, get user input, and validate it
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    int choice;
    char buffer[256];

    while(1){
        printf("%s\n", menuTitle);
        for(int i = 0; i < menuSize; ++i){
            printf("%d. %s\n", i + 1, menuOptions[i]);
        }
        printf("%s", inputMsg);

        // Read input as a string to prevent invalid input issues
        if(fgets(buffer, sizeof(buffer), stdin) != NULL){
            // Try to parse the input as an integer
            if(sscanf(buffer, "%d", &choice) == 1){
                 // Check the choice
                if (choice >= 1 && choice <= menuSize) {
                    return choice; // Return correct choice
                }
            }
        }
        printf("Invalid input! Try again.\n\n"); // Repeat
    }
}

int main()
{
    char menuTitle[256] = "Main menu";
    char inputMsg[256] = "Select a menu item:";
    char *menuOptions[] = {"Add file", "Delete file", "Exit"};
    int menuSize = 3;


    int choice = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    printf("You chose option %d\n", choice);
    return 0;
}
