/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        int sum = INT_MIN;
        int level = 1;
        while(!q.empty()){
            int curr_sum = 0;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                curr_sum += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(curr_sum>sum){
                sum = curr_sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};