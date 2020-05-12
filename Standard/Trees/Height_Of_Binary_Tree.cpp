#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int height(TreeNode* root){
    if(!root)
        return 0;
    return 1 + max(height(root->left), height(root-right));
}

int num_nodes(TreeNode* root){
    if(!root)
        return 0;
    return 1 + num_nodes(root->left) + num_nodes(root->right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}