#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> arr(2*n + 1);
    for(int i=0; i<=n; i++){
        string res = "";
        int gap = n-i;
        int j = 0;
        while(j<gap){
            res += "  ";
            j++;
        }
        for(j = 0; j<=i; j++){
            res += to_string(j);
            if(j!=i)
                res += " ";
        }
        for(j = i-1; j>=0; j--)
            res +=  " " + to_string(j);
        arr[i] = res;
        arr[2*n - i] = res;
    }
    for(int i=0;i<(2*n+1);i++)
        cout<<arr[i]<<"\n";
    return 0;
}