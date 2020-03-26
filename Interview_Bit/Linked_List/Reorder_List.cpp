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
ListNode* Solution::reorderList(ListNode* A) {
    int n = listlength(A);
    if(n<3)
        return A;
    int a,b=n;
    if(n&1)
        a = (n/2)+2;
    else
        a = (n/2)+1;
    A = reverseBetween(A,a,b);
    int cnt=1;
    ListNode* prev = NULL;
    ListNode* curr = A;
    while(cnt<a){
        cnt++;
        prev = curr;
        curr=curr->next;
    }
    prev->next = NULL;
    prev = new ListNode(0);
    ListNode* head = prev;
    cnt = 0;
    while(A || curr){
        if(cnt==0){
            prev->next = A;
            A = A->next;
            cnt ^= 1;
        }
        else{
            prev->next = curr;
            curr = curr->next;
            cnt ^= 1;
        }
        prev = prev->next;
    }
    return head->next;
}
