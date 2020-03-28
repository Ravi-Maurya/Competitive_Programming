/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int, ListNode*> pi;
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int k = A.size();
    priority_queue<pi,vector<pi>,greater<pi>> minheap;
    for(int i=0;i<k;i++)
        minheap.push(make_pair(A[i]->val,A[i]));
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    while(minheap.size()){
        pi top = minheap.top();
        minheap.pop();
        curr->next = new ListNode(top.first);
        curr = curr->next;
        if(top.second->next)
            minheap.push(make_pair(top.second->next->val,top.second->next));
    }
    return head->next;
    
}
