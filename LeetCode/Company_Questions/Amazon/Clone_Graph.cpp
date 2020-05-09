/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> visited;
public:
    Node* cloneGraph(Node* node);
};
Node *Solution::cloneGraph(Node *node) {
    if(!node)
        return NULL;
    Node* root = new Node(node->val);
    visited[node] = root;;
    for(auto x:node->neighbors){
        if(visited.find(x)==visited.end())
            (root->neighbors).push_back(cloneGraph(x));
        else
            (root->neighbors).push_back(visited[x]);
    }
    return root;
}