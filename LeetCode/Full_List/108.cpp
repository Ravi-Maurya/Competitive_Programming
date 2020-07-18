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
    TreeNode* convert(vector<int>& nums, int i, int j){
        if(i==j)
            return new TreeNode(nums[i]);
        if(i>j)
            return nullptr;
        int mid = (i+j)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = convert(nums,i,mid-1);
        res->right = convert(nums,mid+1,j);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums,0,nums.size()-1);
    }
};