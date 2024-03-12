#include <stdio.h>
#define MAX_SIZE 100 

int stack[MAX_SIZE];
int top = -1; 


int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == MAX_SIZE - 1;
}


void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}


int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}


int peek() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

int main() {
    push(10);
    push(20);
    push(30);
	
	
    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());

    printf("Top element after popping: %d\n", peek());

    return 0;
}
