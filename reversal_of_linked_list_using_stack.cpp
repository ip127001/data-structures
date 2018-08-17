#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void reverse()
{
    stack<struct Node *> S;
    struct Node *temp = head;

    while (temp != NULL)
    {
        S.push(temp);
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

void printList(struct Node *p)
{
    struct Node *temp = p;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

int main()
{
    head = NULL;

    insert(40);
    insert(30);
    insert(20);
    insert(10);
    printList(head);

    reverse();

    printList(head);
    return 0;
}