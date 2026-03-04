#include <stdio.h>
#include <stdlib.h>

// a:
typedef struct Stack{
    int *arr;
    int capacity;
}Stack;
// b:
void initStack(Stack *stack){
    stack->arr = NULL;
    stack->capacity = 0;
}
// c:
void printStack(Stack *stack){
    for (int i = 0; i < stack->capacity; ++i){
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
// d:
int getStackSize(Stack *stack){
    return stack->capacity;
}
// d2:
void push(Stack *stack, int value){
    stack->capacity += 1;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(int));
    stack->arr[stack->capacity - 1] = value;
}
// e:
int top(Stack *stack){
    if(stack->capacity == 0) return 0;

    return stack->arr[stack->capacity - 1];
}
// f:
int pop(Stack *stack){
    if (stack->capacity == 0) {
        printf("Stack is empty!\n");
        return 0;
    }
    int temp = top(stack);

    stack->capacity -= 1;

    if (stack->capacity == 0) {
        free(stack->arr);
        stack->arr = NULL;
    } else {
        stack->arr = realloc(stack->arr, stack->capacity * sizeof(int));
    }
    return temp;
}
// g:
void destroyStack(Stack *stack){
    free(stack->arr);
    stack->arr = NULL;
    stack->capacity = 0;
}

int main()
{
    Stack stack1;

    initStack(&stack1);
    printf("Stack initialized.\n");

    // Add el.
    push(&stack1, 5);
    push(&stack1, 10);
    push(&stack1, 15);
    printf("After pushing 5, 10, 15:\n");
    printStack(&stack1);
    printf("Top element: %d\n", top(&stack1));
    printf("Stack size: %d\n\n", getStackSize(&stack1));

    // Pop el.
    printf("Pop element: %d\n", pop(&stack1));
    printf("After pop:\n");
    printStack(&stack1);
    printf("Top element: %d\n", top(&stack1));
    printf("Stack size: %d\n\n", getStackSize(&stack1));

    destroyStack(&stack1);
    printf("Stack destroyed.\n");
    return 0;
}
