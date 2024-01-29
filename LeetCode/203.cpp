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

ListNode *deleteHead(ListNode *l)
{
    // ListNode *p = l;
    // p = p->next;
    // delete (l);
    // return p;
    ListNode *temp = l;
    l = l->next;
    delete (temp);
    return l;
}

ListNode *deleteTail(ListNode *l)
{
    ListNode *p = l;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete (p->next);
    p->next = NULL;
    return l;
}
ListNode *deleteAt(ListNode *l, int k)
{
    ListNode *p = l;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    ListNode *temp = p->next;
    p->next = p->next->next;
    delete (temp);
    return l;
}
ListNode *removeElements(ListNode *head, int val)
{
    vector<int> a;
    ListNode *l = head;
    while (l != NULL)
    {
        a.push_back(l->val);
        l = l->next;
    }
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == val)
        {
            if (i == 0)
                head = deleteHead(head);
            else if (i == n - 1)
                head = deleteTail(head);
            else
                head = deleteAt(head, i);
        }
    }
    return head;
}
int main()
{
    ListNode *head = new ListNode(4);   // create the first node with value 1
    head->next = new ListNode(2);       // create the second node with value 2
    head->next->next = new ListNode(1); // create the third node with value 3
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5); // create the fourth node with value 4
    ListNode *p = removeElements(head, 4);
    // ListNode *p = deleteHead(head);

    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}