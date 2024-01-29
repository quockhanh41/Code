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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *list = list1;
    ListNode *listt = list1;
    while (list->next != NULL)
        list = list->next;
    list->next = list2;
    while (listt->next->next != NULL)
    {
        ListNode *l = listt->next;
        if (l->val > listt->val)
            swap(l->val, listt->val);
        listt = listt->next;
        l = l->next;
    }
    return list1;
}
int main()
{
}