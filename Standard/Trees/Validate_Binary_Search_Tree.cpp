#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool recursive(TreeNode* root, int mn, int mx){
    if(!root)
        return true;
    return ((mn<=root->val && root->val<=mx) && (recursive(root->left,mn,root->val)) && (recursive(root->righ, root->val, mx)));
}

bool validate(TreeNode* root){
    return recursive(root, INT_MIN, INT_MAX);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}