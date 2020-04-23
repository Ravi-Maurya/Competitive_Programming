#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
    int closestValue(TreeNode* root, int target){
        if(!root)
            return -1;
        int res = root->val;
        int mn = INT_MAX;
        while(root){
            if(root->val < target){
                int diff = abs(root->val - target);
                if(diff<mn){
                    mn = diff;
                    res root->val;
                }
                root = root->right;
            }
            else if(root->val > target){
                int diff = abs(root->val - target);
                if(diff<mn){
                    mn = diff;
                    res root->val;
                }
                root = root->left;
            }
            else
                return root->val;
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}