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
int res = INT_MAX;
void find(TreeNode *root, int x)
{
    if (!root)
        return;
    find(root->left);
    if (root->val > x && x < res)
        res = root->val;
    find(root->right);
}
int findSecondMinimumValue(TreeNode *root)
{
    if (!root)
        return -1;
    if (!root->left || !root->right)
        return -1;
    find(root, root->val);
    return res;
}
vector<int> res;
void find(TreeNode *root)
{
    if (!root)
        return;
    find(root->left);
    find(root->right);
    res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    find(root);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}