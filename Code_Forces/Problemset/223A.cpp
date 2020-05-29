#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int s = 0, d = 0;
    int i = 0, j = n-1;
    while(i<=j){
        if(arr[i]>arr[j])
            s += arr[i++];
        else
            s += arr[j--];
        if(i<=j){
            if(arr[i]>arr[j])
                d += arr[i++];
            else
                d += arr[j--];
        }
    }
    cout<<s<<" "<<d<<"\n";
    return 0;
}