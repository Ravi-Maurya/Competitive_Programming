/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> res;

void left(TreeNode* root){
    if(!root)
        return;
    if(root->left){
        res.push_back(root->val);
        left(root->left);
    }
    else if(root->right){
        res.push_back(root->val);
        left(root->right);
    }
    return;
}

void leaf(TreeNode* root){
    if(!root)
        return;
    leaf(root->left);
    if(!root->left && !root->right)
        res.push_back(root->val);
    leaf(root->right);
    return;
}

void right(TreeNode* root){
    if(!root)
        return;
    if(root->right){
        right(root->right);
        res.push_back(root->val);
    }
    else if(root->left){
        right(root->left);
        res.push_back(root->val);
    }
    return;
}

void boundary(TreeNode* root){
    if(!root)
        return;
    res.push_back(root->val);
    left(root->left);
    leaf(root->left);
    leaf(root->right);
    right(root->right);
    return;
}

vector<int> Solution::solve(TreeNode* A) {
    res.clear();
    boundary(A);
    return res;
}
