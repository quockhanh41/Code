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
void traversal(TreeNode *root, int &sum, int &count)
{
    if (!root)
        return;
    sum += root->val;
    count++;
    traversal(root->left, sum, count);
    traversal(root->right, sum, count);
}
bool isAverange(TreeNode *root)
{
    int sum = 0;
    int count = 0;
    traversal(root, sum, count);
    return (root->val == sum / count);
}
int averageOfSubtree(TreeNode *root)
{
    if (!root)
        return 0;
    return isAverange(root) + averageOfSubtree(root->left) + averageOfSubtree(root->right);
}
int main()
{

    return 0;
}