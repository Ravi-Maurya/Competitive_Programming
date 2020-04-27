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
    int len (ListNode* a) {
        if (!a) return 0;
        int cnt=0;
        while (a){
            cnt++;
            a = a->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA && !headB)
            return NULL; 
        auto curr1 = headA;
        auto curr2 = headB;
        int diff = len(headA) - len(headB);
        while (diff > 0) {
            curr1 = curr1->next;
            diff--;
        }
        while (diff < 0) {
            curr2 = curr2->next;
            diff++;
        }
        while (curr1 && curr2) {
            if(curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
    }
};