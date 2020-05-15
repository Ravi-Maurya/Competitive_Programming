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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            set<pair<int,int>> st;
            int size = q.size();
            while(size--){
                auto curr = q.front(); q.pop();
                st.insert({curr.second,curr.first->val});
                if(curr.first->left)
                    q.push({curr.first->left,curr.second-1});
                if(curr.first->right)
                    q.push({curr.first->right,curr.second+1});
            }
            for(auto p: st)
                mp[p.first].push_back(p.second);
        }
        vector<vector<int>> res;
        for(auto it = mp.begin(); it!= mp.end();it++){
            vector<int> tmp;
            for(auto x: it->second)
                tmp.push_back(x);
            res.push_back(tmp);
        }
        return res;
    }
};