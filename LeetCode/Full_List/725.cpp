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
    int listlength(ListNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = listlength(root);
        int i = 0;
        vector<ListNode*> res(k,NULL);
        if(k>=n){
            while(root){
                ListNode* tmp = root->next;
                root->next = NULL;
                res[i++] = root;
                root = tmp;
            }
            return res;
        }
        int parts = n/k;
        int remaining = n%k;
        ListNode* curr = root;
        while(curr){
            int count = (i<remaining)?parts+1: parts;
            ListNode* head = curr;
            ListNode* tmp;
            count -= 1;
            while(curr && count--){
                curr = curr->next;
            }
            if(curr){
                tmp = curr->next;
                curr->next = NULL;
                curr = tmp;
                res[i++] = head;
            }
        }
        return res;
    }
};