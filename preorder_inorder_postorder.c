#include <stdio.h>
#include <stdlib.h>

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

void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);

    return;
}

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);

    return;
}

void postorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);

    return;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);
    root = insert(root, 12);
    root = insert(root, 21);

    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    return 0;
}