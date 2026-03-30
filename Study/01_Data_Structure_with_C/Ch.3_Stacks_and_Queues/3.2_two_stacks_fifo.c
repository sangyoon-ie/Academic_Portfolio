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
    exit(EXIT_FAILURE);
}

element stackEmpty() {
    element err;
    err.key = -1;
    return err;
}

void push1(element item) {
    if (top1 >= MAX_STACK_SIZE - 1) stackFull();
    stack1[++top1] = item;
}

element pop1() {
    if (top1 == -1) return stackEmpty();
    return stack1[top1--];
}

void push2(element item) {
    if (top2 >= MAX_STACK_SIZE - 1) stackFull();
    stack2[++top2] = item;
}

element pop2() {
    if (top2 == -1) return stackEmpty();
    return stack2[top2--];
}

int main() {
    element item;
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        item.key = rand() % 100;
        push1(item);
    }

    while (top1 != -1) {
        push2(pop1());
    }

    while (top2 != -1) {
        item = pop2();
        printf("%d ", item.key);
    }
    printf("\n");

    return 0;
}