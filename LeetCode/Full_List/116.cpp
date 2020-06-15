/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* A) {
        if(!A)
            return A;
        queue<Node*> levelorder;
        levelorder.push(A);
        levelorder.push(NULL);
        while(!levelorder.empty()){
            Node* curr = levelorder.front();
            levelorder.pop();
            if(curr==NULL){
                if(!levelorder.empty())
                    levelorder.push(NULL);
                else
                    break;
            }
            else{
                curr->next = levelorder.front();
                if(curr->left)
                    levelorder.push(curr->left);
                if(curr->right)
                    levelorder.push(curr->right);
            }
        }
        return A;
    }
};