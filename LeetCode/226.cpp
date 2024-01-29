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
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return nullptr;
    if (!root->right)
    {
        root->right = root->left;
        root->left = nullptr;
    }
    else if (!root->left)
    {
        root->left = root->right;
        root->right = nullptr;
    }
    else
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
int main()
{

    return 0;
}