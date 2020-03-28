/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> bst;
TreeNode* curr = NULL;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!bst.empty())
        bst.pop();
    curr = root;
    while(curr){
        bst.push(curr);
        curr = curr->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !bst.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    if(bst.empty())
        return -1;
    curr = bst.top();
    bst.pop();
    int res = curr->val;
    curr = curr->right;
    while(curr){
        bst.push(curr);
        curr = curr->left;
    }
    return res;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
