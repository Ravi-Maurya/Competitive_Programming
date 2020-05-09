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
    ListNode* reverseBetween(ListNode* head, int m, int n);
};
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(!A || !A->next || B==C)
        return A;
    int count = 1;
    ListNode* head = new ListNode(0);
    head->next = A;
    ListNode* nxt = A->next;
    ListNode* prev = head;
    while(count<B && A){
        count++;
        prev = A;
        A = A->next;
        if(A)
            nxt = A->next;
    }
    ListNode* prev1 = prev;
    ListNode* curr1 = A;
    prev = NULL;
    while(count<=C && A){
        count++;
        A->next = prev;
        prev = A;
        A = nxt;
        if(A)
            nxt = A->next;
    }
    prev1->next = prev;
    curr1->next = A;
    return head->next;
}
