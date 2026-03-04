#include <stdio.h>
#include <assert.h>

void strcpy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void strcat(char *dest, char *src){
    int oldEnd = 0;
    while (dest[oldEnd] != '\0') {
        ++oldEnd;
    }

    int i = 0;
    while (src[i] != '\0'){
        dest[oldEnd] = src[i];
        ++i;
        ++oldEnd;
    }
}

int strcmp(char *first, char *second) {
    int i = 0;
    while (first[i] != '\0' && second[i] != '\0') {
        if (first[i] > second[i]) {
            return 1;
        } else if (first[i] < second[i]) {
            return -1;
        }
        i++;
    }

    // If one of the strings ends
    if (first[i] == '\0' && second[i] == '\0') {
        return 0;  // strings equal
    } else if (first[i] == '\0') {
        return -1; // first string shorter
    } else {
        return 1;  // first string longer
    }
}

int main() {
    char c1[50] = "Hello";
    char c2[50] = "world";

    // Tests for strcpy:
    strcpy(c1, c2);
    assert(c1[0] == c2[0]);
    assert(c1[0] == 'w');
    assert(c1[5] == '\0');


    // Tests for strcat:
    strcat(c1, c2);
    assert(c1[5] == c2[0]);// c1 - '\0' was on position 5
    assert(c1[10] == '\0');
    assert(c1[9] == 'd');
    assert(c1[0] == 'w');


    // Tests for strcmp:

    assert(strcmp(c1, c2) == 1);
    strcpy(c1, c2);
    assert(strcmp(c1, c2) == 0);
    strcat(c2, c1);
    assert(strcmp(c1, c2) == -1);

    printf("All tests passed!\n");
    return 0;
}
