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
void sumOne(TreeNode *root, int &ans)
{
    if (!root)
        return;
    if (root->left)
        if (!root->left->left && !root->left->right)
            ans += root->left->val;
    sumOne(root->left, ans);
    sumOne(root->right, ans);
}
int sumOfLeftLeaves(TreeNode *root)
{
    int res = 0;
    sumOne(root, res);
    return res;
}
int main()
{

    return 0;
}