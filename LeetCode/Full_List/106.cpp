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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        if(preorder.size() == 0) {
            return NULL;
        }
        
        unordered_map<int, int> inorderIndex;
        stack<pair<int, TreeNode*>> visitedIndex;
        
        for(int i=0; i<inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        
        TreeNode* root = new TreeNode(preorder[preorder.size()-1]);
        visitedIndex.push({inorderIndex[preorder[preorder.size()-1]], root});
        
        for(int i=preorder.size()-2; i>=0; i--){
            int elementInorderPos = inorderIndex[preorder[i]];
            pair<int, TreeNode*> prevNodePair;
            pair<int, TreeNode*> p_prevNodePair;
            
            bool looped = false;
            while(!visitedIndex.empty()){
                prevNodePair = visitedIndex.top();
                int prevNodeLimit = prevNodePair.first;
                if(prevNodeLimit <= elementInorderPos){
                    break;
                }
                visitedIndex.pop();
                p_prevNodePair = prevNodePair;
                looped = true;
            }
            
            TreeNode* newNode = new TreeNode(preorder[i]);
            if(!looped){
                prevNodePair.second->right = newNode;
            } else {
                p_prevNodePair.second->left = newNode;
            } 
            visitedIndex.push({elementInorderPos, newNode});
        }
        return root;
    }
};