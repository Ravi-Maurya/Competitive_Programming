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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = new ListNode();
        res->next = head;
        ListNode* prev = res;
        while(head && head->next){
            ListNode* curr = head;
            ListNode* curr2 = head->next;
            prev->next = curr2;
            curr->next = curr2->next;
            curr2->next = curr;
            prev = curr;
            head = curr->next;
        }
        return res->next;
    }
};