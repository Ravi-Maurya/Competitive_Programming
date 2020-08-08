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
    int dfs(TreeNode* root, int sum){
        if(!root)
            return 0;
        return ((root->val == sum)?1:0) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return dfs(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
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
class Solution {
public:
    unordered_map<int,int> ump;
    
    int dfs(TreeNode* root, int sum, int prev){
        if(!root)
            return 0;
        int curr = prev + root->val;
        ump[curr]++;
        int left = dfs(root->left,sum,curr);
        int right = dfs(root->right,sum,curr);
        int res = left + right;
        ump[curr]--;
        if(ump.count(curr-sum))
            res += ump[curr-sum];
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) {
        ump[0] = 1;
        if(!root)
            return 0;
        return dfs(root,sum,0);
        
    }
};