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
bool isUnivalTree(TreeNode *root)
{
    if (!root)
        return 1;

    if (root->right)
    {
        if (root->val != root->right->val)
            return 0;
        if (!isUnivalTree(root->right))
            return 0;
    }
    if (root->left)
    {
        if (root->val != root->left->val)
            return 0;
        if (!isUnivalTree(root->left))
            return 0;
    }
    return 1;
}
int main()
{

    return 0;
}