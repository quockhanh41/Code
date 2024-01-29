#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;
int pivotIndex(vector<int>& nums) {
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        rightSum += nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) {
            leftSum += nums[i-1];
        }
        rightSum -= nums[i];
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {-1,-1,2};
    cout << pivotIndex(a);
}