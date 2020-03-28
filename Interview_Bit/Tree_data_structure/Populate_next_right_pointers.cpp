/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A)
        return;
    queue<TreeLinkNode*> levelorder;
    levelorder.push(A);
    levelorder.push(NULL);
    while(!levelorder.empty()){
        TreeLinkNode* curr = levelorder.front();
        levelorder.pop();
        if(curr==NULL){
            if(!levelorder.empty())
                levelorder.push(NULL);
            else
                break;
        }
        else{
            curr->next = levelorder.front();
            if(curr->left)
                levelorder.push(curr->left);
            if(curr->right)
                levelorder.push(curr->right);
        }
    }
    return;
}
