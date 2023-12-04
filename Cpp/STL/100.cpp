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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL || p->val != q->val)
        return false;
    // cout << p->val << " " << q->val << endl;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL and q == NULL)
        return true;
    if (p != NULL and q != NULL and p->val == q->val)
    {
        cout << p->val << " " << q->val << endl;

        if (p->right != NULL || q->right != NULL)
        {
            return isSameTree(p->right, q->right);
        }
        if (p->left != NULL || q->left != NULL)
        {
            return isSameTree(p->left, q->left);
        }
    }
    else
    {
        return false;
    }

    if (p->right == NULL and q->right == NULL and p->left == NULL and q->left == NULL)
        return true;
    else
        return false;
}

int main()
{
    struct TreeNode *p1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *p4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *q1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *q2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *q3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *q4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode *p = p1;
    TreeNode *q = q1;
    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    q1->val = 1;
    q2->val = 2;
    q3->val = 3;
    q4->val = 4;

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = NULL;
    p3->left = NULL;
    p3->right = NULL;
    p4->left = NULL;
    p4->right = NULL;

    q1->left = q2;
    q1->right = q3;
    q2->left = q4;
    q2->right = NULL;
    q3->left = NULL;
    q3->right = NULL;
    q4->left = NULL;
    q4->right = NULL;
    cout << isSameTree(p, q);
}