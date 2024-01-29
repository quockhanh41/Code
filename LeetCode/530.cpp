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
int res = 0;
void visit(TreeNode *root)
{
    if (!root->left && !root->right)
        return;
    visit(root->left);
    if (!root->left)
        res = min(res, root->right->val);
    else if (!root->right)
        res = min(res, root->left->val);
    else
        res = min(res, min(root->val - root->left->val, root->right->val - root->val));
    visit(root->right);
}
int getMinimumDifference(TreeNode *root)
{
    visit(root);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}