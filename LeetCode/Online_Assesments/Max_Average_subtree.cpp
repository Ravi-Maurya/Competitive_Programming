#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode{
    int val;
    vector<TreeNode*> children;
}
long double ans;

pair<long long, int> dfs(TreeNode* root){
    if(!root)
        return {0,0};
    long long int curr_total = root->val;
    int count = 1;
    for(auto child: root->children){
        auto curr = dfs(child);
        curr_total += curr.first;
        count += curr.second;
    }
    long double avg = curr_total/count;
    if(count>1 && avg>ans){
        ans = avg;
    }
    return {curr_total, count};
}

long double solve(TreeNode* root){
    ans = 0.0;
    if(root == NULL)
        return ans;
    dfs(root);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}