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
            return head;
        Node* curr = head;
        while(curr){
            if(curr->child){
                Node* tmp = curr->next;
                curr->next = flatten(curr->child);
                curr->child->prev = curr;
                curr->child = NULL;
                while(curr->next)
                    curr = curr->next;
                if(tmp)
                    tmp->prev = curr;
                curr->next = tmp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};