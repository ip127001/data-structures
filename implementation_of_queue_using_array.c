#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enQueue(int data)
{
    if (isFull())
    {
        printf("queue is full can't insert more \n");
        return;
    }
    else if (isEmpty())
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear = rear + 1;
    }
    arr[rear] = data;

    return;
}

void deQueue()
{
    if (isEmpty())
    {
        printf("can't empty which is already emptyied \n");
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = front + 1;
    }

    return;
}

void printQueue()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{

    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    printQueue();

    deQueue();
    printQueue();

    return 0;
}