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

ListNode* reverseBetween(ListNode* A, int B, int C) {
    if(!A || !A->next || B==C)
        return A;
    int count = 1;
    ListNode* head = new ListNode(0);
    head->next = A;
    ListNode* nxt = A->next;
    ListNode* prev = head;
    while(count<B && A){
        count++;
        prev = A;
        A = A->next;
        if(A)
            nxt = A->next;
    }
    ListNode* prev1 = prev;
    ListNode* curr1 = A;
    prev = NULL;
    while(count<=C && A){
        count++;
        A->next = prev;
        prev = A;
        A = nxt;
        if(A)
            nxt = A->next;
    }
    prev1->next = prev;
    curr1->next = A;
    return head->next;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    int n = listlength(A);
    for(int i=1;i<=n;i+=B){
        A = reverseBetween(A,i,i+B-1);
    }
    return A;
}