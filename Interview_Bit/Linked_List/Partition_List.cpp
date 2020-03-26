/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(!A || !A->next)
        return A;
    ListNode* first, *second, *join, *head;
    first = new ListNode(0);
    head = first;
    second = new ListNode(0);
    join = second;
    while(A){
        if(A->val < B){
            first->next = A;
            first = first->next;
        }
        else{
            second->next = A;
            second = second->next;
        }
        A = A->next;
    }
    first->next = join->next;
    second->next = NULL;
    return head->next;
}
