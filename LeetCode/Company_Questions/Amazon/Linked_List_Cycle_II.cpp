/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head);
};
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A || !A->next || !A->next->next)
        return NULL;
    ListNode* slow = A;
    ListNode* fast = A->next->next;
    while(fast->next && fast->next->next && slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow!=fast)
        return NULL;
    slow = slow->next;
    int count = 1;
    while(slow!=fast){
        count++;
        slow=slow->next;
    }
    slow = A;
    fast = A;
    while(count){
        count--;
        fast = fast->next;
    }
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
