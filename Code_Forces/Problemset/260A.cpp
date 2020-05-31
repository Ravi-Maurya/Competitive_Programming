#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    int n;
    cin>>n;
    bool res = false;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a!=b){
            res = true;
        }
    }
    cout<<(res?"Happy Alex\n":"Poor Alex\n");
    return 0;
}