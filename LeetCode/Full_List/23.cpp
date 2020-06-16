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
    ListNode* merge2Lists(ListNode* A, ListNode* B){
        if(!A)
            return B;
        if(!B)
            return A;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(A && B){
            if(A->val <= B->val){
                curr->next = A;
                A = A->next;
            }
            else{
                curr->next = B;
                B = B->next;
            }
            curr = curr->next;
        }
        curr->next = (A==NULL)?B:A;
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        int n = lists.size();
        if(n==1)
            return lists[0];
        int i = 0;
        int j = n-1;
        while(i<j){
            lists[i] = merge2Lists(lists[i],lists[j]);
            i++;
            j--;
            if(i>=j){
                i = 0;
            }
        }
        return lists[0];
    }
};