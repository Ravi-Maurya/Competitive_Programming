/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL)
        return A;
    ListNode* head = new ListNode(0);
    head->next = A;
    ListNode* prev = head;
    while(A){
        while(A->next && A->val == A->next->val)
            A = A->next;
        if(prev->next == A)
            prev=prev->next;
        else
            prev->next = A->next;
        A = A->next;
    }
    return head->next;
}