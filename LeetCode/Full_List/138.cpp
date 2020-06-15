/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        unordered_map<Node*, Node*> ump;
        Node* trav = head;
        Node* res = new Node(0);
        Node* curr = res;
        while(trav){
            curr->next = new Node(trav->val);
            curr = curr->next;
            ump[trav] = curr;
            trav = trav->next;
        }
        trav = head;
        while(trav){
            if(trav->random){
                ump[trav]->random = ump[trav->random];
            }
            trav = trav->next;
        }
        return res->next;
    }
};