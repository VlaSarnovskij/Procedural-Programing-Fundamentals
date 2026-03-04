#include <stdio.h>
#include <assert.h>

void strncpy(char *dest, char *src, int n) {
    int i = 0;
    for (; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    // If src shorter than n → fill with '\0'
    for (; i < n; ++i) {
        dest[i] = '\0';
    }
    dest[i] = '\0';
}

void strncat(char *dest, char *src, int n){
    int oldEnd = 0;
    while (dest[oldEnd] != '\0') {
        ++oldEnd;
    }

    int i = 0;
    for (; i < n && src[i] != '\0'; ++i, ++oldEnd){
        dest[oldEnd] = src[i];
    }

    dest[oldEnd] = '\0';
}

int strncmp(char *first, char *second, int n) {
    for (int i = 0; i < n; ++i){
        // If reached the end of either string
        if (first[i] == '\0' || second[i] == '\0') {
            if (first[i] == second[i]) {
                return 0; // both ended
            }
            return (first[i] < second[i]) ? -1 : 1;
        }


    // Compare characters
        if (first[i] < second[i]) {
            return -1;
        } else if (first[i] > second[i]) {
            return 1;
        }
    }

    // All n characters are equal
    return 0;
}

int main() {
    char c1[50] = "Hello";
    char c2[50] = "Irmantas";

    // Tests for strncpy:
    strncpy(c1, c2, 3); // c1 = Irm\0\0
    assert(c1[0] == 'I');
    assert(c1[1] == 'r');
    assert(c1[2] == 'm');
    assert(c1[3] == '\0'); // after copied chars → '\0'

    // Tests for strncat:
    strncat(c1, c2, 4); // c1 = IrmIrma\0
    assert(c1[3] == c2[0]);
    assert(c1[7] == '\0');
    assert(c1[6] == 'a');


    // Tests for strncmp:

    assert(strncmp(c1, c2, 3) == 0); // "Irm" ir "Irm"
    assert(strncmp("ABCD", "ABCE", 4) == -1);
    assert(strncmp("ABCD", "ABCE", 2) == 0);
    assert(strncmp("ABCDE", "ABCD", 5) == 1);
    assert(strncmp("ABCD", "ABCDE", 5) == -1);

    printf("All tests passed!\n");
    return 0;
}
