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
TreeNode *res = nullptr;
TreeNode *ans;
void traversal(TreeNode *root)
{
    if (!root)
        return;
    traversal(root->left);
    TreeNode *temp = new TreeNode(root->val);
    if (!res)
    {
        res = temp;
        ans = res;
    }
    else
    {
        res->right = temp;
        res = res->right;
    }
    traversal(root->right);
}
TreeNode *increasingBST(TreeNode *root)
{

    traversal(root);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}