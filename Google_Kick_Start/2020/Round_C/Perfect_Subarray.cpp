#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool check(int n){
    return (sqrt(n)==floor(sqrt(n)));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<int> arr(n), left(n),right(n);
        int res = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(check(arr[i]))
                res++;
        }
        left[0] = arr[0];
        right[n-1]  = arr[n-1];
        for(int i=1;i<n;i++){
            left[i] = left[i-1] + arr[i];
            if(check(left[i]))  res++;
            right[n-i-1] = right[n-i] + arr[n-i-1];
            if(check(right[n-i]))  res++;
        }
        //O(n2)
        // for(int i=0; i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int tmp = arr[j]-(i==0?0:arr[i-1]);
        //         if(tmp>=0 && check(tmp))
        //             res++;
        //     }
        // }
        // int tmp = 0;
        // int high = ceil(sqrt(mx));
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        //     if(check(arr[i]))
        //         res++;
        //     for(int k = 1; k<=high; k++){
        //         int next = arr[i] + k*k;
        //         if(next>mx)
        //             break;
        //         cout<<next<<" ";
        //         if(hash.count(next))
        //             tmp += hash[next];
        //     }
        //     cout<<"\n";
        // }
        // res += tmp;
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}