#include <iostream>
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
int sum = 0;

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        if (sum == targetSum)
            return 1;
    hasPathSum(root->left, targetSum - sum);
    hasPathSum(root->right, targetSum - sum);
    return 0;
}
int main()
{
}