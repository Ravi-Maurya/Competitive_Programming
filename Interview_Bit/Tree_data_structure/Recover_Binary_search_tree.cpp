/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
    stack<TreeNode*> inorder;
    TreeNode* curr = A;
    vector<int> res;
    while(curr || !inorder.empty()){
        while(curr){
            inorder.push(curr);
            curr = curr->left;
        }
        curr = inorder.top();
        inorder.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    int i=0,j=res.size()-1;
    vector<int> ans(2,-1);
    int sm = -1, bg = -1;
    while(i<res.size()-1 && j>0 ){
        if(res[i+1]-res[i]<0 && bg==-1)
            bg = i;
        if(res[j]-res[j-1]<0 && sm==-1)
            sm = j;
        if(bg!=-1 && sm!=-1)
            break;
        i++;
        j--;
    }
    ans[0] = res[sm];
    ans[1] = res[bg];
    return ans;
}
