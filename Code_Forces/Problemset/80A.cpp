#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    if(n<=10 || n-10>=12){
        cout<<0;
    }
    else{
        int k = n-10;
        if(k!=10)
            cout<<4;
        else
            cout<<15;
    }
    cout<<"\n";
    return 0;
}