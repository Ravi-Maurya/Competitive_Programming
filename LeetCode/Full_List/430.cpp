/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        Node* res = head;
        while(head){
            if(head->child != NULL){
                Node* tmp = head->next;
                Node* tmp2 = flatten(head->child);
                head->next = tmp2;
                head->child = NULL;
                tmp2->prev = head;
                while(tmp2->next)
                    tmp2 = tmp2->next;
                tmp2->next = tmp;
                if(tmp)
                    tmp->prev = tmp2;
                head = tmp;
            }
            else{
                head = head->next;
            }
        }
        return res;
    }
};