#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int prev = 0;
    int x;
    cin>>x;
    int curr = 1;
    while(6*x >= (curr*(curr+1)*(curr+2))){
        prev = curr;
        curr++;
    }
    cout<<prev<<"\n";
    return 0;
}