#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->data = data;

    return newNode;
}

struct Node *insert(struct Node *head, int data)
{
    if (head == NULL)
    {
        head = createNode(data);
    }
    else if (head->data > data)
    {
        head->left = insert(head->left, data);
    }
    else
    {
        head->right = insert(head->right, data);
    }
    return head;
}

void traversal(struct Node *root)
{
    queue<struct Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        struct Node *current = Q.front();
        cout << current->data;
        cout << "\n";
        if (current->right != NULL)
            Q.push(current->right);
        if (current->left != NULL)
            Q.push(current->left);
        Q.pop();
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);

    traversal(root);

    return 0;
}