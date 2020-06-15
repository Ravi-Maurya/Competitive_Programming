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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prel, int preh, int inl,unordered_map<int,int>& ump){
        if(prel>preh)
            return NULL;
        int idx = ump[preorder[prel]];
        TreeNode* root = new TreeNode(preorder[prel]);
        root->left = build(preorder, inorder, prel+1, prel+(idx-inl), inl,ump);
        root->right = build(preorder, inorder, prel+(idx-inl)+1, preh, idx+1,ump);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size())
            return NULL;
        unordered_map<int,int> ump;
        for(int i = 0; i<inorder.size(); i++)
            ump[inorder[i]] = i;
        for(auto& x: preorder)
            if(!ump.count(x))
                return NULL;
        int n = inorder.size();
        return build(preorder,inorder,0,n-1,0,ump);
    }
};