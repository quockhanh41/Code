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
void solve(TreeNode *&root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return;
    else if (!root1)
        root1 = new TreeNode(root2->val);
    else if (root1 && root2)
        root1->val += root2->val;
    else
        return;
    solve(root1->left, root2->left);
    solve(root1->right, root2->right);
}
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return nullptr;
    else if (!root1)
        root1 = new TreeNode(root2->val);
    else if (root1 && root2)
        root1->val += root2->val;
    else
        return nullptr;
    TreeNode *l = (root1->left, root2->left);
    if (l)
        return l;
    TreeNode *r = (root1->right, root2->right);
    if (r)
        return l;
    return root1;
}
int main()
{

    return 0;
}