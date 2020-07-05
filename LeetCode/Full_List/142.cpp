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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        if(!fast->next || !fast->next->next)
            return NULL;
        slow = slow->next;
        int count = 1;
        while(slow!=fast){
            count++;
            slow = slow->next;
        }
        fast = head;
        slow = head;
        while(count--){
            fast =fast->next;
        }
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};