#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int solve1(vector<int>& nums, int target){//O(nlogn)
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1;
    int count=0;
    while(i<j){
        int curr_sum = nums[i]+nums[j];
        if(curr_sum==target){
            ++count;
            ++i;
            --j;
            while(i<j && nums[j]==nums[j+1])
                --j;
            while(i<j && nums[i]==nums[i-1])
                ++i;
        }
        else if(curr_sum<target)
            i++;
        else
            j--;
    }
    return count;
}

int solve2(vector<int>& nums, int target){//o(n)
    unordered_set<int> visited, numset;
    int count = 0;
    for(auto n:nums){
        int diff = target - n;
        if(numset.find(diff)!=numset.end()){
            if(visited.find(diff)==visited.end())
                count++;
            visited.insert(n);
            visited.insert(diff);
        }
        numset.insert(n);
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}