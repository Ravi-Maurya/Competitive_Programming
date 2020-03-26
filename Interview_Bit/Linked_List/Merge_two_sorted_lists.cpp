/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head = new ListNode(0);
    ListNode* res = head;
    while(A && B){
        if(A->val <= B->val){
            head->next = A;
            head = head->next;
            A = A->next;
        }
        else{
            head->next = B;
            head = head->next;
            B = B->next;
        }
    }
    if(A)
        head->next = A;
    else if(B)
        head->next = B;
    return res->next;
}
