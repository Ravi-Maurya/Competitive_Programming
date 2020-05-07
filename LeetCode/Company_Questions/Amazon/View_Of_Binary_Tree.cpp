#include <bits/stdc++.h> 
using namespace std;

class Solution{
    struct TreeNode{
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    public:
    
    void left_recursive(TreeNode* root, int level, int& max_level, vector<int>& res){
        if(!root)
            return;
        if(max_level < level){
            res.push_back(root->val);
            max_level = level;
        }
        left_recursive(root->left, level +1, max_level, res);
        left_recursive(root->right, level +1, max_level, res);
        return;
    }
    vector<int> left_view(TreeNode* root){
        int max_level = 0;
        vector<int> res;
        left_recursive(root, 1, max_level,res);
        return res;
    }

    void right_recursive(TreeNode* root, int level, int& max_level, vector<int>& res){
        if(!root)
            return;
        if(max_level < level){
            res.push_back(root->val);
            max_level = level;
        }
        right_recursive(root->right, level +1, max_level, res);
        right_recursive(root->left, level +1, max_level, res);
        return;
    }
    vector<int> right_view(TreeNode* root){
        int max_level = 0;
        vector<int> res;
        right_recursive(root, 1, max_level,res);
        return res;
    }
    void top_recursive(TreeNode* root, int d, int l,map<int,pair<int,int>>& mp ){
        if(!root)
            return;
        if(mp.count(d)==0)
            mp[d] = {root->val, l};
        else if(mp[d].second<l)
            mp[d] = {root->val, l};
        
        top_recursive(root->left, d-1, l+1, mp);
        top_recursive(root->right, d+1, l-1, mp);
        return;
    }
    vector<int> top_view(TreeNode* root){
        vector<int> res;
        if(!root)
            return res;
        map<int,pair<int,int>> ump;
        top_recursive(root,0, 0, ump);
        for(auto it=mp.begin(); it!=mp.end(); it++)
            res.push_back(it->second.first);
        return res;
    }
};

class Boundary{
    struct TreeNode{
        TreeNode* left;
        TreeNode* right;
        int val;
    };

    public:
    void boundary_left(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        if(root->left){
            res.push_back(root->val);
            boundary_left(root->left, res);
        }
        else if(root->right){
            res.push_back(root->val);
            boundary_left(root->right, res);
        }
        return;
    }
    void leaves(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        leaves(root->left);
        if(!root->left && !root->right)
            res.push_back(root->val);
        leaves(root->right);
        return;
    }
    void boundary_right(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        if(root->right){
            res.push_back(root->val);
            boundary_right(root->right, res);
        }
        else if(root->left){
            res.push_back(root->val);
            boundary_right(root->left, res);
        }
        return;
    }
    vector<int> boundary_view(TreeNode* root){
        vector<int> res;
        if(!root)
            return res;
        res.push_back(root->val);
        boundary_left(root->left, res);
        leaves(root->left, res);
        leaves(root->right, res);
        boundary_right(root->right, res)
        return res;
    }
}