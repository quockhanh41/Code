#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *middleNode(ListNode *head)
{
    ListNode *p = head;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    if (cnt == 2)
        return head->next;
    for (int i = 0; i < cnt / 2; i++)
    {
        head = head->next;
    }
    cout << cnt;
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);   // create the first node with value 1
    head->next = new ListNode(2);       // create the second node with value 2
    head->next->next = new ListNode(3); // create the third node with value 3
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5); // create the fourth node with value 4
    ListNode *p = middleNode(head);
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
}