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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0)
            return NULL;
        TreeNode* curr;
        TreeNode* root;
        stack<TreeNode*> res;
        int i=0,j=0;
        root = new TreeNode(preorder[i++]);
        res.push(root);
        while(true){
            if(inorder[j] == res.top()->val){
                curr = res.top();res.pop();
                j++;
                if(j==inorder.size())
                    break;
                if(!res.empty() && inorder[j] == res.top()->val)
                    continue;
                curr->right = new TreeNode(preorder[i++]);
                res.push(curr->right);
            }
            else{
                curr = new TreeNode(preorder[i++]);
                res.top()->left = curr;
                res.push(curr);
            }
        }
        return root;
    }
};