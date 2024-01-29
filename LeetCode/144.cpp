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
void Traversal(vector<int> &v, TreeNode *root)
{
    if (!root)
        return;
    v.push_back(root->val);
    Traversal(v, root->left);
    Traversal(v, root->right);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    Traversal(res, root);
    return res;
}
int main()
{

    return 0;
}