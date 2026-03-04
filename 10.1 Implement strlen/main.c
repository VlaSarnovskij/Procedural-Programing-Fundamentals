#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Step 2:
int strlen(char *str){
    int size = 0;
    while (str[size] != '\0'){
        ++size;
    }

    return size;
}

int main()
{
    // Step 1:
    assert(strlen("Hello!") == 6);
    assert(strlen("Pass") == 4);
    assert(strlen("") == 0);
    assert(strlen("X") == 1);

    printf("All tests passed!\n");
    return 0;
}
