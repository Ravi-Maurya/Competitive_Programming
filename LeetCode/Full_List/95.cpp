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
    vector<TreeNode*> generateSubTrees(int i, int j){
        vector<TreeNode*> res;
        if(i>j) return res;
        for(int k=i; k<=j; k++){
            vector<TreeNode*> left_tree = generateSubTrees(i,k-1);
            vector<TreeNode*> right_tree = generateSubTrees(k+1,j);
            if(left_tree.size()==0) left_tree.push_back(nullptr);
            if(right_tree.size()==0) right_tree.push_back(nullptr);
            for(auto subLeftTree: left_tree){
                for(auto subRightTree: right_tree){
                    TreeNode* mytree = new TreeNode(k,subLeftTree,subRightTree);
                    res.push_back(mytree);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateSubTrees(1,n);
    }
};