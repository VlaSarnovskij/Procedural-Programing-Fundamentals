#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
    Node* head = NULL;
    addElement(&head, 5);
    addElement(&head, 20);
    addElement(&head, -2);
    addElement(&head, 1);

    printf("Before removeMinNode: ");
    printList(head);

    removeMinNode(&head);

    printf("After removeMinNode: ");
    printList(head);

    clearList(&head);

    return 0;
}
