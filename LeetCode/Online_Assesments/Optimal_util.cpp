#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
bool compare(vector<int> x, vector<int> y){
    return x[1]<=y[1];
}

vector<vector<int>> solve(vector<vector<int>>& a, vector<vector<int>>& b, int k){
    sort(a.begin(),a.end(),compare);
    sort(b.begin(),b.end(),compare);
    int l = 0;
    int r = b.size()-1;
    vector<vector<int>> res;
    int curr_max = INT_MIN;
    while(l<a.size() && r>=0){
        int curr_sum = a[l][1] + b[r][1];
        if(curr_sum>k){
            --r;
        }
        else{
            if(curr_max<=curr_sum){
                if(curr_max<curr_sum){
                    curr_max = curr_sum;
                    res.clear();
                }
                res.push_back({a[l][0],b[r][0]});
                int idx = r-1;
                while(idx>=0 && b[idx][1]==b[idx+1][1])
                    res.push_back({a[l][0],b[idx--][0]});
            }
            ++l;
        }
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}