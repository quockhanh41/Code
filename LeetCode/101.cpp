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
bool solve(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    if (root1->val != root2->val)
        return 0;
    if (!solve(root1->left, root2->right) || !solve(root1->right, root2->left))
        return 0;
    return 1;
}

bool isSymmetric(TreeNode *root)
{
    return solve(root->left, root->right);
}
int main()
{

    return 0;
}