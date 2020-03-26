/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return 1;
    if(A->next->next==NULL)
        return (A->val == A->next->val);
    ListNode* slow;
    ListNode* fast;
    ListNode* prev;
    ListNode* curr;
    prev = NULL;
    slow = A;
    curr = slow->next;
    fast = A;
    int is_odd = false;
    while(true){
        if(fast->next == NULL){
            is_odd = true;
            break;
        }
        if(fast->next->next == NULL)
            break;
        fast = fast->next->next;
        slow->next = prev;
        prev = slow;
        slow = curr;
        curr = curr->next;
    }
    slow->next = prev;
    prev = slow;
    slow = curr;
    curr = curr->next;
    if (is_odd)
        prev = prev->next;
    while(prev && slow){
        if(slow->val != prev->val)
            return 0;
        slow = slow->next;
        prev = prev->next;
    }
    return 1;
}
