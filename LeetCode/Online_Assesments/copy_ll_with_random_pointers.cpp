#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
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
        unordered_map<Node*, Node*> ump;
        Node* curr = head;
        Node* head1 = new Node(0);
        Node* curr1 = head1;
        while(curr){
            Node* tmp = new Node(curr->val);
            curr1->next = tmp;
            curr1 = curr1->next;
            ump[curr] = curr1;
            curr = curr->next;
        }
        curr1 = head1->next;
        curr = head;
        while(curr1 && curr){
            if(curr->random)
                curr1->random = ump[curr->random];
            curr1 = curr1->next;
            curr = curr->next;
        }
        return head1->next;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}