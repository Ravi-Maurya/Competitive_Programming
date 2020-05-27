#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int x,y;
    cin>>x>>y;
    if(x>=0 && y>=0){
        cout<<0<<" "<<(y+x)<<" "<<(y+x)<<" "<<0;
    }
    else if(x<0 && y>=0){
        cout<<(x-y)<<" "<<0<<" "<<0<<" "<<(y-x);
    }
    else if(x>=0 && y<0){
        cout<<0<<" "<<(y-x)<<" "<<(x-y)<<" "<<0;
    }
    else{
        cout<<(x+y)<<" "<<0<<" "<<0<<" "<<(x+y);
    }
    cout<<"\n";
    return 0;
}