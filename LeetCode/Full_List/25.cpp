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
    
    ListNode* reverseList(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(k--){
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1)
            return head;
        int count = 0;
        ListNode* curr = head;
        while(count<k && curr!=NULL){
            curr = curr->next;
            count++;
        }
        if(count==k){
            ListNode* reversed = reverseList(head,k);
            head->next = reverseKGroup(curr,k);
            return reversed;
        }
        return head;
    }
};

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
    
    ListNode* reverseList(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(k--){
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1)
            return head;
        ListNode* curr = head;
        ListNode* tail = NULL;
        ListNode* res = NULL;
        while(curr){
            int count = 0;
            curr = head;
            while(count<k && curr){
                curr=curr->next;
                count++;
            }
            if(count==k){
                ListNode* reversed = reverseList(head,k);
                if(!res)
                    res = reversed;
                if(tail)
                    tail->next = reversed;
                tail = head;
                head = curr;
            }
        }
        if(tail)
            tail->next = head;
        return res?res:head;
    }
};