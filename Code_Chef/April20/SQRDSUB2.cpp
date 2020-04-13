#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin>>t;
    while (t--){
        long long int n;
        cin>>n;
        long long int arr[n];
        long long int buffer[n];
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] % 2 != 0)
                buffer[i] = 0;
            else{
                if(arr[i] % 4 == 0)
                    buffer[i] = 2;
                else
                    buffer[i] = 1;
            }
        }
        unordered_map<int,int> prev;
        long long int count = 0;
        long long int sum = 0;
        for(long long int i=0;i<n;i++){
            sum += buffer[i];
            if(sum == 1)
                count += 1;
            if(prev.find(sum - 1) != prev.end())
                count += prev[sum-1];
            prev[sum]++;
        }
        long long int total = (n*(n+1))/2;
        cout<<total-count<<endl; 
    }
}