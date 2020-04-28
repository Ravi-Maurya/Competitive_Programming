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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        if(!root)
            return res;
        vector<int> tmp;
        while(!q.empty()){
            tmp.clear();
            int size = q.size();
            while(size--){
                Node* curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                for(auto child: curr->children){
                    if(child!=NULL)
                        q.push(child);
                }
            }
            if(tmp.size()>0)
                res.push_back(tmp);
        }
        return res;
    }
};