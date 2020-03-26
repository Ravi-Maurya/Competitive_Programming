/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* listlength(ListNode* tmp){
    int cnt = 0;
    ListNode* prev = NULL;
    while(tmp){
        cnt++;
        prev = tmp;
        tmp = tmp->next;
    }
    ListNode* t = new ListNode(cnt);
    t->next = prev;
    return t;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* tmp = listlength(A);
    int n = tmp->val;
    B %= n;
    if (B==0)
        return A;
    ListNode* last = tmp->next;
    last->next = A;
    int i = n-B;
    ListNode* prev = NULL;
    while(i){
        i--;
        prev = A;
        A = A->next;
    }
    prev->next = NULL;
    return A;
}
