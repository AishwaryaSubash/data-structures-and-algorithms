#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return false;
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
        return false;
    TreeNode *ptr1 = root->left;
    TreeNode *ptr2 = root->right;
    while (ptr1->val == ptr2->val)
    {
        return isSymmetric(ptr1->left);
    }
}

int main()
{
    struct TreeNode *p1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    TreeNode *root = p1;
    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    p5->val = 2;
    p6->val = 4;
    p7->val = 3;

    p1->left = p2;
    p1->right = p5;
    p2->left = p3;
    p2->right = p4;
    p3->left = NULL;
    p3->right = NULL;
    p4->left = NULL;
    p4->right = NULL;
    p5->left = p6;
    p5->right = p7;
    p6->left = NULL;
    p6->right = NULL;
    p7->left = NULL;
    p7->right = NULL;

    cout << isSymmetric(root);
}