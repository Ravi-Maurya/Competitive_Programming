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

int binary_search_index(vector<int>& nums, int target, bool first, int l, int h){
    /*
    Input -> arr, target, (true/false), 0, size of arr;
    Functioning -> first = true will give the lower_bound for that value that is if target present then that index else the index where it must have been
    first = false, does same for backwards direction,
    O(logn) - TC
    */
    while(l<h){
        int mid = l + (h-l)/2;
        if(target<nums[mid] || (first && target==nums[mid]))
            h = mid;
        else
            l = mid+1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}