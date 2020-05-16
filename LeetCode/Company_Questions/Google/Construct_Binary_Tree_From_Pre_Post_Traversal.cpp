/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recursive(vector<int>& pre, vector<int>& post, int i, int j, int n){
        if(n==0)
            return NULL;
        TreeNode* root = new TreeNode(pre[i]);
        if(n==1)
            return root;
        int l = 1;
        for(;l<n;++l)
            if(post[j+l-1]==pre[i+1])
                break;
        root->left = recursive(pre,post,i+1,j,l);
        root->right = recursive(pre,post,i+1+l,j+l,n-l-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if(n!=post.size())
            return NULL;
        return recursive(pre,post,0,0,n);
    }
};