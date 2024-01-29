#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{

    ListNode *pre = new ListNode();
    pre->next = head;
    ListNode *res = pre;
    while (head != nullptr)
    {
        if (head->next && head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
                head = head->next;
            pre->next = head->next;
        }
        else
            pre = pre->next;
        head = head->next;
    }

    return res->next;
}
int main()
{
    ListNode *a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(4)))))));
    ListNode *p = deleteDuplicates(a);
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
}