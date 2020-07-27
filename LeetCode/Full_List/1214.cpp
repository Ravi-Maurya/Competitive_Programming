/*
1214. Two Sum BSTs
Medium

171

15

Add to List

Share
Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:



Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
Example 2:



Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
 

Constraints:

Each tree has at most 5000 nodes.
-10^9 <= target, node.val <= 10^9
*/

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1 || !root2)
            return false;
        stack<TreeNode*> st;
        unordered_set<int> ust;
        while(!st.empty() || root1 != NULL){
            while(root1){
                st.push(root1);
                root1 = root1->left;
            }
            root1 = st.top();st.pop();
            ust.insert(target - root1->val);
            root1 = root1->right;
        }
        while(!st.empty() || root2 != NULL){
            while(root2){
                st.push(root2);
                root2 = root2->left;
            }
            root2 = st.top();st.pop();
            if(ust.count(root2->val))
                return true;
            root2 = root2->right;
        }
        return false;
    }
};