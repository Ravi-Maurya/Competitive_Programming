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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr =head;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum = ((l1==NULL)?0:l1->val) + ((l2==NULL)?0:l2->val) + carry;
            carry = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if(l1!=NULL)
                l1 = l1->next;
            if(l2!=NULL)
                l2 = l2->next;
        }
        return head->next;
    }
};