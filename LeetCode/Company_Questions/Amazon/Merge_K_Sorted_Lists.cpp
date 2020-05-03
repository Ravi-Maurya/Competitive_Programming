#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        for(auto x: lists)
            if(x)
                pq.push({x->val,x});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            curr->next = top.second;
            if(top.second->next)
                pq.push({top.second->next->val, top.second->next});
            curr = curr->next;
        }
        return head->next;
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
class Solution2 {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(0);
        ListNode* curr =head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(!l1)
            curr->next = l2;
        else
            curr->next = l1;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        int interval = 1;
        while(interval<n){
            for(int i=0; i<n-interval; i+=interval*2)
                lists[i] = merge(lists[i],lists[i+interval]);
            interval *= 2;
        }
        return lists[0];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}