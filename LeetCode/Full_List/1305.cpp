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
    void get_list(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        get_list(root->left,res);
        res.push_back(root->val);
        get_list(root->right,res);
        return;
    }
    vector<int> merge(vector<int>& list1,vector<int>& list2){
        int n1 = list1.size(), n2=list2.size();
        vector<int> res(n1+n2);
        int i=0,j=0,k=0;
        while(i<n1 && j<n2){
            if(list1[i]<=list2[j])
                res[k++] = list1[i++];
            else
                res[k++] = list2[j++];
        }
        while(i<n1){
            res[k++] = list1[i++];
        }
        while(j<n2){
            res[k++] = list2[j++];
        }
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1,list2;
        get_list(root1,list1);
        get_list(root2,list2);
        return merge(list1,list2);
    }
};