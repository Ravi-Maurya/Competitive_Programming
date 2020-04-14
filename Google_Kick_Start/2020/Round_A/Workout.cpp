// Binary Search

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int l=1,r=arr[n-1]-arr[0];
        while(l<r){
            int mid = (l+r)>>1;
            int tmp = 0;
            for(int i=1;i<n;i++){
                int d = arr[i] - arr[i-1];
                tmp += (d+mid-1)/mid-1;
            }
            if(tmp<=k)
                r = mid;
            else
                l = mid+1;
        }
        cout<<"Case #"<<test<<": "<<l<<"\n";
    }
    return 0;
}




// // Test set 1 Passed but WA in Test 2

// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC optimize ("-O3")

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL); cout.tie(NULL);
//     int t;
//     cin>>t;
//     for(int test = 1; test <= t; test++){
//         int n,k;
//         cin>>n>>k;
//         priority_queue<pair<int,pair<int,int>>> pq;
//         vector<int> arr(n);
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//             if(i!=0){
//                 pq.push(make_pair(arr[i]-arr[i-1],make_pair(arr[i-1],arr[i])));
//             }
//         }
//         while((k--) && (pq.top().first > 1)){
//             pair<int,pair<int,int>> tp = pq.top();
//             pq.pop();
//             int x = (tp.second.first + tp.second.second)>>1;
//             pq.push(make_pair(x-tp.second.first,make_pair(tp.second.first,x)));
//             pq.push(make_pair(tp.second.second-x,make_pair(x,tp.second.second)));
//         }
//         int res = pq.top().first;
//         cout<<"Case #"<<test<<": "<<res<<"\n";
//     }
//     return 0;
// }