#include <iostream>
#include <vector>
#include <algorithm>
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

void traversal(TreeNode *root, vector<int> &v)
{
    if (!root)
        return;
    traversal(root->left, v);
    v.push_back(root->val);
    traversal(root->right, v);
}
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    vector<int> v1;
    vector<int> v2;
    traversal(root1, v1);
    traversal(root2, v2);
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
            res.push_back(v1[i++]);
        else
            res.push_back(v2[j++]);
    }
    if (i >= v1.size())
    {
        while (j < v2.size())
            res.push_back(v2[j++]);
    }
    else if (j >= v2.size())
    {
        while (i < v1.size())
            res.push_back(v1[i++]);
    }
    return res;
}
int main()
{

    return 0;
}