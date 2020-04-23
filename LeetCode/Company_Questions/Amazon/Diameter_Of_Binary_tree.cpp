#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int depth(TreeNode* root){
        if(!root)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans,l+r+1);
        return max(l,r)+1;
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans-1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}