#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int xi,yi;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            int t;
            cin>>t;
            if(t==1){
                xi = i;
                yi = j;
            }
        }
    cout<<(abs(2-xi) + abs(2-yi))<<"\n";
    return 0;
}