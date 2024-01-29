#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head)
{
    int res = 0;
    ListNode *p = head;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    cnt--;
    while (cnt != -1)
    {
        // cout << head->val << " " << pow(2, cnt) << endl;
        res += pow(2, cnt) * head->val;
        cnt--;
        head = head->next;
    }
    return res;
}
int main()
{
    ListNode *head = new ListNode(1);   // create the first node with value 1
    head->next = new ListNode(0);       // create the second node with value 2
    head->next->next = new ListNode(1); // create the third node with value 3
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5); // create the fourth node with value 4
    // ListNode *p = middleNode(head);
    // while (p)
    // {
    //     cout << p->val << " ";
    //     p = p->next;
    // }
    cout << getDecimalValue(head);
}