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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(true){
            if(!curr)
                break;
            while(curr && (!prev || prev->val >= curr->val)){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            if(curr){
                ListNode* it = prev;
                while(it->next && it->next->val < curr->val){
                    it = it->next;
                }
                ListNode* tmp = curr->next;
                curr->next = it->next;
                it->next = curr;
                curr = tmp;
            }
        }
        return prev;
    }
};