#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Struct for deep tests
struct Point {
    int x;
    float y;
};

void memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    // Copy every byte
    for (size_t i = 0; i < n; ++i) {
        d[i] = s[i];
    }
}

int memcmp(void *first, const void *second, size_t n){
    unsigned char *f = first;
    const unsigned char *s = second;
    // Compare bytes
    for (size_t i = 0; i < n; ++i) {
        if(f[i] > s[i]) return 1;
        else if(f[i] < s[i]) return -1;
    }
    return 0;
}

void memset(void *dest, char value, size_t n){
    unsigned char *d = dest;
    // Insert src in every byte
    for (size_t i = 0; i < n; ++i) {
        d[i] = value;
    }

}

void *memchr(void *dest, char value, size_t n) {
    const unsigned char *d = dest;
    // Find value in dest
    for (size_t i = 0; i < n; ++i) {
        if (d[i] == value) {
            return (void *)(d + i);
        }
    }
    return NULL; // if value was not found
}

int main() {
    // Tests for memcpy:
    int a[3] = {1, 2, 3};
    int b[3];

    memcpy(b, a, sizeof(a));

    assert(b[0] == a[0]);
    assert(b[1] == a[1]);
    assert(b[2] == a[2]);

    struct Point p1 = {10, 3.5};
    struct Point p2;

    memcpy(&p2, &p1, sizeof(p1));

    assert(p1.x == p2.x);
    assert(p1.y == p2.y);


    // Tests for memcmp:
    assert(memcmp(a, b, sizeof(a)) == 0);
    b[0] = 5;
    assert(memcmp(a, b, sizeof(a)) == -1);
    assert(memcmp(&p1, &p2, sizeof(p1)) == 0);

    // Tests for memset:
    memset(a, 0, sizeof(a));
    assert(a[0] == 0);
    assert(a[2] == 0);
    memset(&p1, 0, sizeof(p1));
    assert(p1.x == 0);
    assert(p1.y == 0);

    // Tests for memchr:
    assert(memchr(a, 0, sizeof(a)) == &a[0]);
    assert(memchr(a, 1, sizeof(a)) == NULL);
    assert(memchr(&p1.x, 0, sizeof(p1)) == &p1.x);
    char ch[] = "Hello";
    assert(memchr(ch, 'l', 5) == &ch[2]);

    printf("All tests passed!\n");

    return 0;
}
