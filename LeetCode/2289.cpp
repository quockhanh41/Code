#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int totalSteps(vector<int> &nums)
{
    stack<pair<int, int>> st;
    int n = nums.size();
    int ans = 0;
    st.push({nums[n - 1], 0});
    for (int i = n - 2; i >= 0; i--)
    {
        int cnt = 0;
        while (!st.empty() && st.top().first < nums[i])
        {

        cnt = max(cnt + 1, st.top().second);
            
            st.pop();
        }
        ans = max(cnt, ans);
        st.push({nums[i], cnt});
        cout << nums[i] << " " << cnt << endl;
    }

    return ans;
}
int main()
{
    vector<int> a = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 7, 6, 4,8, 11};
    // totalSteps(a);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cout << sumOfTwoInterger(1,2);
    return 0;
}