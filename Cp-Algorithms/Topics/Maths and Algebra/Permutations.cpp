#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

void next_permutation(vector<int>& nums){//O(n)
    int n = nums.size(), i;
    int invert = n-2;
    while(invert>=0 && nums[invert]>=nums[invert+1])
        invert--;
    if(invert==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(i = n-1; i>=invert+1; i--){
        if(nums[invert] < nums[i]){
            swap(nums[invert],nums[i]);
            break;
        }
    }
    reverse(nums.begin()+(invert+1), nums.end());
    return;
}

int factorial(int n){
    int res = 1;
    for(int i=1;i<=n;i++)
        res = res*i;
    return res;
}

vector<int> kth_permutation(vector<int>& nums, int k){
    int n = nums.size();
    if(n==0)
        return {};
    int f = factorial(n-1);
    int pos = k/f;
    k = k%f;
    vector<int> res;
    res.push_back(nums[pos]);
    nums.erase(nums.begin()+pos);
    auto t = kth_permutation(nums,k);
    res.emplace_back(t.begin(),t.end());
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}