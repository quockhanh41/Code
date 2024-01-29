#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode *head)
{
    vector<int> arr;
    ListNode *p = head;
    ListNode *l = head;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    int cnt2 = cnt;
    cnt2 = cnt / 2;
    while (cnt2--)
    {
        arr.push_back(l->val);
        l = l->next;
    }
    reverse(arr.begin(), arr.end());

    if (cnt % 2 == 1)
        l = l->next;
    int i = 0;
    while (l != nullptr)
    {

        // cout << i << " " << arr[i] << " " << l->val << endl;
        if (arr[i] != l->val)
            return false;
        i++;
        l = l->next;
    }
    return true;
}
int main()
{
    ListNode *head = new ListNode(1);   // create the first node with value 1
    head->next = new ListNode(0);       // create the second node with value 2
    head->next->next = new ListNode(1); // create the third node with value 3
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1); // create the fourth node with value 4
    cout << isPalindrome(head);
}