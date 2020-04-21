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
    bool equals(TreeNode* s, TreeNode* t){
        if(s==NULL && t==NULL)
            return true;
        if(s==NULL || t==NULL)
            return false;
        return s->val == t->val && equals(s->left,t->left) && equals(s->right,t->right);
    }
    bool traverse(TreeNode* s, TreeNode* t){
        return (s!=NULL && (equals(s,t) || traverse(s->left,t) || traverse(s->right,t)));
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s,t);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}