#include <iostream>
#include <vector>
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

// int length(TreeNode *root)
// {
//     if (!root)
//         return 0;
//     return 1 + max(length(root->left), length(root->right));
// }
// void traversal(int &res, TreeNode *root)
// {
//     if (!root)
//         return;
//     diameterOfBinaryTree(root->left);
//     diameterOfBinaryTree(root->right);
//     res = max(res, length(root->left) + length(root->right));
// }
// int diameterOfBinaryTree(TreeNode *root)
// {
//     int res = 0;
//     traversal(res, root);
//     return res;
// }
int solve(TreeNode *node, int &diameter)
{
    if (node == NULL)
        return 0;

    int l = solve(node->left, diameter);
    int r = solve(node->right, diameter);

    diameter = max(diameter, l + r);

    return 1 + max(l, r);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;

    solve(root, diameter);

    return diameter;
}
int main()
{

    return 0;
}