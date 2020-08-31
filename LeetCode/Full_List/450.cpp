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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        if(root->left == NULL){
            TreeNode* tmp = root->right;
            delete(root);
            return tmp;
        }
        else if(root->right == NULL){
            TreeNode* tmp = root->left;
            delete(root);
            return tmp;
        }
        else{
            TreeNode* curr = root;
            TreeNode* succ = root->right;
            while(succ->left){
                curr = succ;
                succ = succ->left;
            }
            if(curr != root){
                curr->left = succ->right;
            }
            else{
                curr->right = succ->right;
            }
            root->val = succ->val;
            delete(succ);
            return root;
        }
        
    }
};