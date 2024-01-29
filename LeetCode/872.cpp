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
void getLeafs(TreeNode *root, vector<int> &v)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        v.push_back(root->val);
    getLeafs(root->left, v);
    getLeafs(root->right, v);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1;
    getLeafs(root1, v1);
    vector<int> v2;
    getLeafs(root2, v2);
    return v1 == v2;
}
int main()
{

    return 0;
}