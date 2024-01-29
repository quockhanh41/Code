#include <iostream>
#include <vector>
#include <string>
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
void solve(TreeNode *root, string temp, vector<string> &ans)
{
    temp += to_string(root->val) + "->";
    if (!root->left && !root->right)
    {
        if (!temp.empty())
        {
            temp.erase(temp.size() - 1);
            temp.erase(temp.size() - 1);
        }
        ans.push_back(temp);
    }
    else
    {
        if (root->left)
            solve(root->left, temp, ans);
        if (root->right)
            solve(root->right, temp, ans);
    }
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    solve(root, "", res);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}