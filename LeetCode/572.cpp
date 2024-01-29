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
bool isTheSameSubTree(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    if (root1->val != root2->val)
        return 0;
    if (!isTheSameSubTree(root1->left, root2->left) || !isTheSameSubTree(root1->right, root2->right))
        return 0;
    return 1;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root)
        return 0;
    if (isTheSameSubTree(root, subRoot))
        return 1;
    if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
        return 1;
    return 0;
}
int main()
{

    return 0;
}