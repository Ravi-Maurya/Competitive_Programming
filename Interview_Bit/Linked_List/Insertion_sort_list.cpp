/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if (!A || !A->next)
        return  A;
    ListNode* head = NULL;
    ListNode* curr = A;
    while(curr){
        ListNode* tmp = curr;
        curr=curr->next;
        if(!head || head->val >= tmp->val){
            tmp->next = head;
            head = tmp;
        }
        else{
            ListNode* temp = head;
            while(temp){
                ListNode* s = temp;
                temp = temp->next;
                if(!s->next || s->next->val > tmp->val){
                    tmp->next = s->next;
                    s->next = tmp;
                    break;
                }
            }
        }
    }
    return head;
}
