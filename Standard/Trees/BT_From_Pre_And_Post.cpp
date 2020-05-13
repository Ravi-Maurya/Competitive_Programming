#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* pre_post(vector<int>& preorder, vector<int>& postorder, int& preorder_idx, int i, int j, int size){// (preorder, ostorder,0,0,n-1,n-1)
    if(preorder_idx>=size || i>j)
        return NULL;
    TreeNode* root = new TreeNode(preorder[preorder_idx++]);
    if(i==j)
        return root;
    int x;
    for(x = i; x<=h; x++)
        if(preorder[preorder_idx] == postorder[k])
            break;
    if(x<=j){
        root->left = pre_post(preorder,postorder,preorder_idx,i,x,size);
        root->right = pre_post(preorder,postorder,preorder_idx,x+1,j,size);
    }
    return root;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}