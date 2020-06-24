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
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* curr = odd;
        ListNode* head2 = even;
        int flag = 1;
        while(head){
            if(flag==1){
                odd->next = head;
                head = head->next;
                odd = odd->next;
                odd->next = nullptr;
            }
            else{
                even->next = head;
                head = head->next;
                even = even->next;
                even->next = nullptr;
            }
            flag ^= 1;
        }
        odd->next = head2->next;
        return curr->next;
    }
};
