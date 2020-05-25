#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin>>n;
    int arr[n];
    int sum1 = 0, sum2 = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    sum1 = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        if(sum1<=sum2) 
            sum1 += arr[i];
        else
            sum2 += arr[i];
    }
    // cout<<sum1<<" "<<sum2<<"\n";
    string s = (sum1==sum2) ? "YES\n" : "NO\n";
    cout<<s;
    return 0;
}