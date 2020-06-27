/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()) {
       
            int size = q.size();
            for(int i=0; i < size; i++) {
                Node* current_node = q.front();
                q.pop();
                for(auto child : current_node->children) {
                     q.push(child);
                }
            }
                 ans++;
        }
        return ans;
    }
};