#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        for(int i=0; i<nums.size(); i++){
            int diff = target-nums[i];
            if(ump.find(diff)!=ump.end()){
                return {ump[diff],i};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}