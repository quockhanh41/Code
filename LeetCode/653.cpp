#include <iostream>
#include <vector>
#include <map>
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
vector<int> f;
void getData(TreeNode *root, vector<int> &f)
{
    if (root)
    {
        getData(root->left, f);
        f.push_back(root->val);
        getData(root->right, f);
    }
}
bool findTarget(TreeNode *root, int k)
{
    getData(root, f);
    sort(f.begin(), f.end());
    int l = 0;
    int r = f.size() - 1;
    while (l < r)
    {
        int sum = f[l] + f[r];
        if (sum == k)
            return 1;
        else if (sum > k)
            r--;
        else
            l++;
    }
    return 0;
}
int main()
{
}