#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recursive(TreeNode* root, int sum, int curr_sum, vector<int>& tmp, vector<vector<int>>& res){
    if(!root)
        return;
    tmp.push_back(root->val);
    if(!root->left && !root->right && curr_sum+root->val == sum)
        res.push_back(tmp);
    else{
        recursive(root->left,sum,curr_sum+root->val,tmp,res);
        recursive(root->right,sum,curr_sum+root->val,tmp,res);
    }
    tmp.pop_back();
    return;
}

vector<vector<int>> solve(TreeNode* root, int sum){
    vector<vector<int>> res;
    vector<int> tmp;
    recursive(root,sum,0,tmp,res);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}