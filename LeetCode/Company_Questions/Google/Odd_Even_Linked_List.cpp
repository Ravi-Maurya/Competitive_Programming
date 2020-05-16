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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* curr = head;
        ListNode* head1 = odd;
        ListNode* head2 = even;
        while(curr && curr->next){
            odd->next = curr;
            even->next = curr->next;
            curr = curr->next->next;
            odd = odd->next;
            even = even->next;
        }
        if(curr){
            odd->next = curr;
            curr->next = head2->next;
            even->next = NULL;
        }
        else{
            odd->next = head2->next;
            even->next = NULL;
        }
        return head1->next;
    }
};