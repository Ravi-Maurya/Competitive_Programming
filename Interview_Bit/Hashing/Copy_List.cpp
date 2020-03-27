/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A)
        return A;
    RandomListNode* tmp1 = A;
    while(tmp1){
        RandomListNode* copy = new RandomListNode(tmp1->label);
        copy->next = tmp1->next; // new.next = old.next
        tmp1->next = copy;// old.next = new
        tmp1 = copy->next;//old = new.next(i.e. previous old.next)
    }
    tmp1 = A;
    RandomListNode* tmp2 = A->next;
    while(tmp1){
        if(tmp1->random)
            tmp2->random = tmp1->random->next;
        else
            tmp2->random = NULL;
        
        tmp1 = tmp2->next;
        if(tmp1)
            tmp2 = tmp1->next;
    }
    RandomListNode* head = A->next;
    tmp1 = A;
    tmp2 = A->next;
    while(tmp1){
        tmp1->next = tmp2->next;
        tmp1 = tmp1->next;
        if(tmp1){
            tmp2->next = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    return head;
}
