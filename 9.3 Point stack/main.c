#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a):
typedef struct Point{
    double x;
    double y;
}Point;

Point createInvalidPoint() {
    Point p;
    p.x = 0.0;
    p.y = 0.0;
    return p;
}

// b):
void printPoint(Point p){
    printf("(%.1f, %.1f)\n", p.x, p.y);
}

// c):
Point createPoint(double x, double y){
    Point p = {x, y};
    return p;
}

// d):
double getDistance(Point a, Point b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}


// a:
typedef struct Stack{
    Point *arr;
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
        double dist = getDistance(stack->arr[i], createPoint(0,0));
        printf("(%.1f, %.1f) Distance to origin: %.1f\n", stack->arr[i].x, stack->arr[i].y, dist);
    }
}

// d:
int getStackSize(Stack *stack){
    return stack->capacity;
}
// d2:
void push(Stack *stack, Point value){
    stack->capacity += 1;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(Point));
    stack->arr[stack->capacity - 1] = value;
}
// e:
Point top(Stack *stack){
    if(stack->capacity == 0) return createInvalidPoint();

    return stack->arr[stack->capacity - 1];
}
// f:
Point pop(Stack *stack){
    if (stack->capacity == 0) {
        printf("Stack is empty!\n");
        return createInvalidPoint();
    }
    Point temp = top(stack);

    stack->capacity -= 1;

    if (stack->capacity == 0) {
        free(stack->arr);
        stack->arr = NULL;
    } else {
        stack->arr = realloc(stack->arr, stack->capacity * sizeof(Point));
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
    Point point = {1, 2};
    push(&stack1, point);

    point.x = 5;
    point.y = 7;
    push(&stack1, point);

    point.x = 4;
    point.y = 2;
    push(&stack1, point);

    point.x = 11;
    point.y = 8;
    push(&stack1, point);

    point.x = 3;
    point.y = 2;
    push(&stack1, point);

    printf("After pushing points:\n");
    printStack(&stack1);

    point = top(&stack1);
    printf("Top element: (%.1f;%.1f)\n", point.x, point.y);
    printf("Stack size: %d\n\n", getStackSize(&stack1));

    // Pop el.
    Point popped = pop(&stack1);
    printf("Pop element: (%.1f;%.1f)\n", popped.x, popped.y);

    printf("After pop:\n");
    printStack(&stack1);
    point = top(&stack1);
    printf("Top element: (%.1f;%.1f)\n", point.x, point.y);
    printf("Stack size: %d\n\n", getStackSize(&stack1));

    destroyStack(&stack1);
    printf("Stack destroyed.\n");
    return 0;
}
