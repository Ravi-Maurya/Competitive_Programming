#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void left_view_helper(TreeNode*  root, int curr_level, int max_level){
    if(!root)
        return;
    if(max_level<curr_level){
        cout<<root->val<<"\t";
        max_level = curr_level;
    }
    left_view_helper(root->left,curr_level+1,max_level);
    left_view_helper(root->right,curr_level+1,max_level);
    return;
}

void left_view(TreeNode* root){
    int level = 0;
    left_view_helper(root,1,level);
}

void right_view_helper(TreeNode*  root, int curr_level, int max_level){
    if(!root)
        return;
    if(max_level<curr_level){
        cout<<root->val<<"\t";
        max_level = curr_level;
    }
    right_view_helper(root->right,curr_level+1,max_level);
    right_view_helper(root->left,curr_level+1,max_level);
    return;
}

void right_view(TreeNode* root){
    int level = 0;
    right_view_helper(root,1,level);
}

void top_view(TreeNode* root){
    if(!root)
        return;
    queue<pair<TreeNode*,int>> q;
    map<int,int> mp;
    int horizontal = 0;
    q.push({root,horizontal});
    while (!q.empty()){
        auto curr = q.front();q.pop();
        if(mp.count(curr.second)==0)
            mp[curr.second] = curr.first->val;
        if(root->left){
            q.push({root->left,curr.second-1});
        }
        if(root->right){
            q.push({root->right,curr.second+1});
        }
    }
    for(auto it = mp.begin(); it!=mp.end();it++)
        cout<<it->second;
    return;    
}

void bottom_view(TreeNode* root){
    if(!root)
        return;
    queue<pair<TreeNode*,int>> q;
    map<int,int> mp;
    int horizontal = 0;
    q.push({root,horizontal});
    while (!q.empty()){
        auto curr = q.front();q.pop();
        mp[curr.second] = curr.first->val;
        if(root->left){
            q.push({root->left,curr.second-1});
        }
        if(root->right){
            q.push({root->right,curr.second+1});
        }
    }
    for(auto it = mp.begin(); it!=mp.end();it++)
        cout<<it->second;
    return;    
}

void leaves(TreeNode* root){
    if(!root)
        return;
    leaves(root->left);
    if(!root->left && !root->right)
        cout<<root->val;
    leaves(root->right);
    return;
}

void left_view_without_leaves(TreeNode* root){
    if(!root)
        return NULL;
    if(root->left){
        cout<<root->val;
        left_view_without_leaves(root->left);
    }
    else if(root->right){
        cout<<root->val;
        left_view_without_leaves(root->right);
    }
    return;
}

void right_view_without_leaves(TreeNode* root){
    if(!root)
        return NULL;
    if(root->right){
        right_view_without_leaves(root->right);
        cout<<root->val;
    }
    else if(root->left){
        right_view_without_leaves(root->left);
        cout<<root->val;
    }
    return;
}

void boundary_view(TreeNode* root){
    if(!root)
        return;
    cout<<root->val;
    left_view_without_leaves(root->left);
    leaves(root->left);
    leaves(root->right);
    right_view_without_leaves(root->right);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}