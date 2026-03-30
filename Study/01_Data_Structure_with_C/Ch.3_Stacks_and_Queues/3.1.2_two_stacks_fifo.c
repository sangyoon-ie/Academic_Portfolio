/*  write a program to 
generate ten random integer numbers, and push them to a stack. 
Then print out in the order of first-in-first-out */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int key;
} element;

element stack1[MAX_STACK_SIZE];
int top1 = -1;

element stack2[MAX_STACK_SIZE];
int top2 = -1;

void stackFull() {
    fprintf(stderr, "Stack is full, cannot add element\n");
    exit(EXIT_FAILURE);
}

element stackEmpty() {
    fprintf(stderr, "Stack is empty, cannot pop element\n");
    exit(EXIT_FAILURE);
}

void push1(element item) {
    if (top1 >= MAX_STACK_SIZE - 1)
        stackFull();
    stack1[++top1] = item;
}

element pop1() {
    if (top1 == -1)
        return stackEmpty();
    return stack1[top1--];
}

void push2(element item) {
    if (top2 >= MAX_STACK_SIZE - 1)
        stackFull();
    stack2[++top2] = item;
}

element pop2() {
    if (top2 == -1)
        return stackEmpty();
    return stack2[top2--];
}

int main() {
    element item;

    srand((unsigned int)time(NULL));

    printf("1. Generating 10 random numbers and pushing to Stack 1:\n");
    for (int i = 0; i < 10; i++) {
        item.key = rand() % 100;
        printf("%d ", item.key);
        push1(item);
    }
    printf("\n\n");

    while (top1 != -1) {
        push2(pop1());
    }

    printf("2. Printing from Stack 2 (FIFO order):\n");
    while (top2 != -1) {
        item = pop2();
        printf("%d ", item.key);
    }
    printf("\n");

    return 0;
}