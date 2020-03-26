/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int listlength(ListNode* tmp){
    int cnt = 0;
    while(tmp){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = listlength(A);
    // cout<<n;
    int i = n-B;
    if (i<0)
        i=0;
    if(i==0)
        if(A)
            return A->next;
    ListNode* head = new ListNode(0);
    head->next = A;
    while(i-1){
        i--;
        A=A->next;
    }
    A->next = A->next->next;
    return head->next;
}
