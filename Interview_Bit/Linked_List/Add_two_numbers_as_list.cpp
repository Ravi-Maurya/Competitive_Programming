/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    int carry = 0, sm = 0;
    sm = A->val + B->val + carry;
    A = A->next;
    B = B->next;
    ListNode* curr = new ListNode(sm%10);
    carry = sm/10;
    ListNode* head = curr;
    while(A || B || carry){
        sm = carry;
        if(A)
            sm += A->val;
        if(B)
            sm += B->val;
        curr->next = new ListNode(sm%10);
        carry = sm/10;
        curr = curr->next;
        if(A)
            A = A->next;
        if(B)
            B = B->next;
    }
    return head;
}
