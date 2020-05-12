#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
bool check(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2)
        return true;
    else if(root1 && root2)
        return ((root1->val == root2->val) && check(root1->left,root2->right) && check(root1->right,root2->left));
    else
        return false;
}
 
int isSymmetric(TreeNode* A) {
    return (!A || check(A->left,A->right));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}