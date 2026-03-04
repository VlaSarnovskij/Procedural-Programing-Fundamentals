#include <stdlib.h>
#include "list.h"

void addElement(Node** head, int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return;
    }

    node->value = value;

    node->next = *head;

    *head = node;
}

void removeMinNode(Node** head) {
    if (*head == NULL) return; // empty list

    Node* minNode = *head;
    Node* minPrev = NULL;

    Node* prev = NULL;
    Node* current = *head;

    // searching for min node
    while (current != NULL) {
        if (current->value < minNode->value) {
            minNode = current;
            minPrev = prev;
        }
        prev = current;
        current = current->next;
    }

    // removing minNode
    if (minPrev == NULL) {
        // min - first node(head)
        *head = (*head)->next;
    } else {
        minPrev->next = minNode->next;
    }

    free(minNode);
}

void printList(Node* head){
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void clearList(Node** head){
    while (*head != NULL) {
            Node* temp = *head;
            *head = (*head)->next;
            free(temp);
    }
}
