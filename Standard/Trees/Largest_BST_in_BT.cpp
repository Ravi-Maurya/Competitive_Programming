#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct treeData{
    int mn, mx, size;
    bool isBst;
    treeData(){
        mn = INT_MAX;
        mx = INT_MIN;
        isBst = 1;
        size = 0;
    }
};

treeData largest(TreeNode* root){
    if(!root)
        return new treeData();
    auto left = largest(root->left);
    auto right= largest(root->right);
    treeData d = new treeData();
    if(!left.isBst || !right.isBst || left.mx>root->val || right.mn <= root->val){
        d.isBst = 0;
        d.size = max(left.size, right.size);
        return d;
    }
    d.isBst = 1;
    d.size = left.size + 1 + right.size;
    d.mn = root->left?left.mn : root->val;
    d.mx = root->right?right.mx: root->val;
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}