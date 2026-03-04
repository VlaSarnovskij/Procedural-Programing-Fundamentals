#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *strchr(char *str, char ch){
    int i = 0;
    while (1) {
        if (str[i] == ch) return &str[i];
        if (str[i] == '\0') return NULL;
        i++;
    }
}

char *strrchr(char *str, char ch){
    char *ptr = NULL;
    int i = 0;

    while (1) {
        if (str[i] == ch) ptr = &str[i];
        if (str[i] == '\0') break;
        i++;
    }

    return ptr;
}

char *strstr(char *str, char *substr){
    if (*substr == '\0') return str;

    for (int i = 0; str[i] != '\0'; i++) {
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j]) {
            j++;
        }
        if (substr[j] == '\0') {
            return &str[i];
        }
    }

    return NULL;
}


int main()
{
    char text[] = "Hello world!";
    char *p = strchr(text, 'o');

    // Tests for strchr:
    assert(strchr("Test", 'e') != NULL);
    assert(strchr(text, 'b') == NULL);
    assert(strchr(text, 'H') == &text[0]);
    assert(strchr(text, '!') == &text[11]);
    assert(strchr(text, '\0') == &text[12]);

    // Tests for strrchr:
    assert(strrchr("Test", 'e') != NULL);
    assert(strrchr(text, 'b') == NULL);
    assert(strrchr(text, 'l') == &text[9]);
    assert(strrchr(text, 'o') == &text[7]);
    assert(strrchr(text, '!') == &text[11]);
    assert(strrchr(text, '\0') == &text[12]);

    // Tests for strstr:
    assert(strstr("Test", "est") != NULL);
    assert(strstr(text, "world") == &text[6]);
    assert(strstr(text, "") == &text[0]);
    assert(strstr(text, "ello") == &text[1]);
    assert(strstr(text, "abc") == NULL);

    printf("All test passed!\n");
    return 0;
}
