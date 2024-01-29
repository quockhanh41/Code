#include <iostream>
#include <vector>
#include <cmath>
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
int sumOne(TreeNode *root, int ans)
{
    if (!root)
        return 0;

    ans = ans * 2 + root->val;

    if (!root->left && !root->right)
        return ans;

    return sumOne(root->left, ans) + sumOne(root->right, ans);
}
int main()
{

    return 0;
}