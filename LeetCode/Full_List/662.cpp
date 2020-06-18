class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        long long res = 0;
        while(!q.empty()) {
            long long left_most = q.front().second;
            long long right_most = left_most;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front().first;
                right_most = q.front().second;
                q.pop();
                if(curr->left != NULL)
                    q.push({curr->left, 2 * right_most});
                if(curr->right != NULL)
                    q.push({curr->right, 2 * right_most + 1});
            }
            res = max(res, right_most - left_most + 1);
        }
        return res;
    }
};