#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int odd = 0, even = 0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a&1)
            odd++;
        else
            even++;
    }
    if(odd&1){
        cout<<odd<<"\n";
    }
    else{
        cout<<even<<'\n';
    }
    return 0;
}