/**Reverse Morris Inorder
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* get_succ(TreeNode* root){
        TreeNode* succ = root->right;
        while(succ->left && succ->left!=root)
            succ = succ->left;
        return succ;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;
        while(curr){
            if(curr->right == NULL){
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            }
            else{
                TreeNode* succ = get_succ(curr);
                if(succ->left==NULL){
                    succ->left = curr;
                    curr = curr->right;
                }
                else{
                    succ->left = NULL;
                    sum += curr->val;
                    curr->val = sum;
                    curr = curr->left;
                }
            }
        }
        return root;
    }
};

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
class Solution2 {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;
        stack<TreeNode*> s;
        while(!s.empty() || curr){
            while(curr){
                s.push(curr);
                curr=  curr->right;
            }
            curr = s.top();
            s.pop();
            sum += curr->val;
            curr->val = sum;
            curr = curr->left;
        }
        return root;
    }
};