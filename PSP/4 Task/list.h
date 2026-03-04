#ifndef LIST_H		// Include guard
#define LIST_H

#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;


void addElement(Node** head, int value);

void removeMinNode(Node** head);

void printList(Node* head);

void clearList(Node** head);
#endif
