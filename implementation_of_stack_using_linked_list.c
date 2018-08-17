#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top;

void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;

    return;
}

void pop()
{
    struct Node *temp = top;
    top = temp->next;

    return;
}

void printStack()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    top = NULL;

    push(10);
    push(20);
    push(30);
    push(40);

    pop();
    printf("top to bottom stack list: ");
    printStack();
    return 0;
}