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
    ListNode* curr;
    ListNode* tmp;
    curr=A;
    while(curr!=NULL){
        tmp = curr;
        while(curr->next!=NULL && curr->val == curr->next->val)
            curr = curr->next;
        tmp->next = curr->next;
        tmp = tmp->next;
        curr = curr->next;
    }
    return A;
}
