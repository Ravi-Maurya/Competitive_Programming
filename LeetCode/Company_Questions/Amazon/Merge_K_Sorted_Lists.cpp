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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}