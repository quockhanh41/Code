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
int H_max(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(H_max(root->left), H_max(root->right));
}
int solve(TreeNode *root, int h, int Hmax)
{
    if (!root)
        return 0;
    if (h == Hmax)
        return root->val;
    return solve(root->left, h + 1, Hmax) + solve(root->right, h + 1, Hmax);
}

int deepestLeavesSum(TreeNode *root)
{
    return solve(root, 1, H_max(root));
}
int main()
{

    return 0;
}