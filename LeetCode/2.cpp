#include <iostream>
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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *res = new ListNode();
    ListNode *ans = res;
    int mem = 0;
    while (l1 != nullptr || l2 != nullptr || mem)
    {
        int sum = 0;
        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += mem;
        res->next = new ListNode(sum % 10);
        mem = sum / 10;
        res = res->next;
    }
    return ans->next;
}
int main()
{
    ListNode *a = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *b = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *head = addTwoNumbers(a, b);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}