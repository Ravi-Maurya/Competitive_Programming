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
    int listlenght(ListNode* A){
        int count = 0;
        while(A){
            count++;
            A = A->next;
        }
        return count;
    }
    int adjust(ListNode* head){
        if(!head)
            return 0;
        int sum = adjust(head->next) + head->val;
        head->val = sum%10;
        return sum/10;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int s1 = listlenght(l1), s2 = listlenght(l2);
        int diff = abs(s1-s2);
        if(s2>s1)
            swap(l1,l2);
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while(l1 && diff--){
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l1){
            curr->next = new ListNode(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        res = res->next;
        int carry = adjust(res);
        if(carry){
            ListNode* ans = new ListNode(carry);
            ans->next = res;
            return ans;
        }
        return res;
    }
};