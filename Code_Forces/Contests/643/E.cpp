#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
 
unsigned long long int helper(int n, vector<int>& height, int& a, int& r, int& m, int h){
    unsigned long long int cost = 0;
    // without moving tiles i.e. just adding or removing it;
    // and also dividing the array in two sets i.e. greater than curr h and less then h;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int> max_heap;
    int same = 0;
    for(int i=0; i<n; i++){
        if(height[i]>h){
            min_heap.push(height[i]);
            cost += r*(height[i]-h);
        }
        else if(height[i]<h){
            max_heap.push(height[i]);
            cost += a*(h-height[i]);
        }
        else{
            same++;
        }
    }
    if(min_heap.empty() || max_heap.empty())
        return cost;
    unsigned long long int tmp = 0;
    while(!min_heap.empty() && !max_heap.empty()){
        int big = min_heap.top(); min_heap.pop();
        int small = max_heap.top(); max_heap.pop();
        int need = h - small;
        int extra = big - h;
        tmp += m*(min(need,extra));
        if(need>extra){
            small = small + extra;
            max_heap.push(small);
        }
        else if(extra>need){
            big = big - need;
            min_heap.push(big);
        }
    }
    while(!max_heap.empty()){
        tmp += (h-max_heap.top())*a;
        max_heap.pop();
    }
    while(!min_heap.empty()){
        tmp += (min_heap.top()-h)*r;
        min_heap.pop();
    }
    return cost<tmp?cost:tmp;
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,a,r,m;
    cin>>n>>a>>r>>m;
    vector<int> height(n);
    int max_height = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>height[i];
        if(height[i]>max_height)
            max_height = height[i];
    }
    unsigned long long int res = INT_MAX;
    // int high = 1 + max_height;
    // int low = 0;
    for(int mid = 0; mid<=max_height; mid++){
        unsigned long long int tmp = helper(n,height,a,r,m,mid);
        if(tmp<res)
            res = tmp;
    }
    // while(low<high){
    //     int mid = (low+high)>>1;
    //     unsigned long long int bm = (mid>0)?helper(n,height,a,r,m,mid-1):INT_MAX;
    //     unsigned long long int tmp = helper(n,height,a,r,m,mid);
    //     unsigned long long int am = helper(n,height,a,r,m,mid+1);
    //     res = min(res,tmp);
    //     if(bm<=tmp)
    //         high = mid;
    //     else if(am<=tmp)
    //         low = mid+1;
    //     else{
    //         res = tmp;
    //         break;
    //     }
    // }
    cout<<res<<"\n";
    return 0;
}