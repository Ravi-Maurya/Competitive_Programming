/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head);
};
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A || !A->next)
        return A;
    ListNode* first, *second, *prev;
    ListNode* head = new ListNode(0);
    head->next = A;
    first = A;
    second = A->next;
    prev = head;
    while(first && second){
        ListNode* tmp = second->next;
        second->next = first;
        first->next = tmp;
        prev->next = second;
        prev = first;
        first = tmp;
        if(first)
            second = first->next;
        else
            second = NULL;
    }
    return head->next;
}