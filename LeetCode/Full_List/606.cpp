/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        stack<TreeNode*> st;
        st.push(t);
        unordered_set<TreeNode*> visited;
        string res = "";
        while(!st.empty()){
            t = st.top();
            if(visited.count(t)){
                st.pop();
                res += ")";
            }
            else{
                visited.insert(t);
                res += "(" + to_string(t->val);
                if(!t->left && t->right)
                    res += "()";
                if(t->right)
                    st.push(t->right);
                if(t->left)
                    st.push(t->left);
            }
        }
        return res.substr(1,res.size()-2);
    }
};