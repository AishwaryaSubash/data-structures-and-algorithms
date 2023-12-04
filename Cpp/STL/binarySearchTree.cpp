#include <bits/stdc++.h>
using namespace std;

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *create(int val)
{
    BST *node = new BST();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct BST *insert(struct BST *root, int val)
{
    if (root == NULL)
    {
        return create(val);
    }
    else
    {
        if (root->data > val)
            insert(root->left, val);
        else if (root->data < val)
            insert(root->right, val);
    }
    return root;
}

void inorderTraversal(struct BST *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    struct BST *root = NULL;
    root = insert(root, 2);
    insert(root, 6);
    insert(root, 3);
    insert(root, 4);

    inorderTraversal(root);
}