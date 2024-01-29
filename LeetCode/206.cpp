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
ListNode *reverseList(ListNode *head)
{
    ListNode *next = NULL;
    ListNode *pre = NULL;
    ListNode *current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}
int main()
{
    // Alternatively, you can use the ListNode constructor with both value and next pointer to create a linked list:
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode *p = reverseList(head);

    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}