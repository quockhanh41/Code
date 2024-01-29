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

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    if (!original)
        return nullptr;
    if (target == original)
        return cloned;

    TreeNode *l = getTargetCopy(original->left, cloned->left, target);
    if (l)
        return l;
    TreeNode *r = getTargetCopy(original->right, cloned->right, target);
    if (r)
        return r;

    return nullptr;
}

int main()
{

    return 0;
}