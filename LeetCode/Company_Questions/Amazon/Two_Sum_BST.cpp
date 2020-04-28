class Solution{
    public:
        vector<int> inorderTraversal(TreeNode* A);
        bool isTwoSum(TreeNode* A, TreeNode* B, int k){
            vector<int> inord1 = inorderTraversal(A), inord2 = inorderTraversal(B);
            int i=0; j = inord2.size()-1;
            while(i<inord1.size() && j>=0){
                int curr_sum = inord1[i] + inord2[j];
                if(curr_sum == k)
                    return true;
                else if(curr_sum<k)
                    i++;
                else
                    j--;
            }
            return false;
        }
};
vector<int> Solution::inorderTraversal(TreeNode* A) {
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
    return res;
}