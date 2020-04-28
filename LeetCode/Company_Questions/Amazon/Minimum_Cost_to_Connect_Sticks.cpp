#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int solve(vector<int>& sticks){
    priority_queue<int,vector<int>,greater<int>> pq(sticks.begin(),sticks.end());
    int curr_sum , total_sum = 0;
    while(pq.size()>1){
        curr_sum = 0;
        curr_sum += pq.top();
        pq.pop();
        curr_sum += pq.top();
        pq.pop();
        total_sum += curr_sum;
        pq.push(curr_sum);
    }
    return total_sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}