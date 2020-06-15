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
    ListNode *reverse(ListNode* head){
        if(!head)
            return NULL;
        ListNode *curr = head, *prev = NULL;
        while(curr){
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *fast = head, *slow = head, *tmp;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        tmp = slow->next;
        slow->next = NULL;
        fast = reverse(tmp);
        slow = head;
        while(slow && fast){
            tmp = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow = slow->next;
            slow->next = tmp;
            slow = slow->next;
        }
    }
};