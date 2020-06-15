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
    pair<int,ListNode*> length(ListNode* head){
        int len = 0;
        ListNode* prev = NULL;
        while(head){
            len++;
            prev = head;
            head = head->next;
        }
        return {len,prev};
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        auto p = length(head);
        k = k%p.first;
        ListNode* curr = p.second;
        curr->next = head;
        ListNode* res = head;
        k = p.first-k;
        while(k--){
            res = res->next;
            curr = curr->next;
        }
        curr->next = NULL;
        return res;
    }
};