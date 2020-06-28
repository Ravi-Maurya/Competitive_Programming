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


//Single PASS
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
    unordered_map<Node*, Node*> ump;
    
    Node* getCloned(Node* head){
        if(!head)
            return NULL;
        if(!ump.count(head))
            ump[head] = new Node(head->val);
        return ump[head];
    }
    
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* old = head;
        Node* curr = new Node(old->val);
        ump[old] = curr;
        while(old){
            curr->random = getCloned(old->random);
            curr->next = getCloned(old->next);
            old = old->next;
            curr = curr->next;
        }
        return ump[head];
    }
};



// O(1) space 
// idea is to store the new node as
// A->B->C to A->A'->B->B'->C->C'
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
        Node* curr = head;
        while(curr){
            Node* nxt = new Node(curr->val);
            nxt->next = curr->next;
            curr->next = nxt;
            curr = nxt->next;
        }
        curr = head;
        while(curr){
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* res = head->next;
        Node* now = head->next;
        while(curr){
            curr->next = curr->next->next;
            res->next = (res->next!=NULL)?res->next->next:NULL;
            
            curr = curr->next;
            res = res->next;
        }
        return now;
    }
};