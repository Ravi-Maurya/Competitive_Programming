#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
const long long int mod = 1000000007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int firstidx = -1, secondidx = -1;
        bool following = true;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            if(tmp==1){
                if(firstidx==-1)
                    firstidx = i;
                else if(secondidx==-1)
                    secondidx = i;
                else{
                    firstidx = secondidx;
                    secondidx = i;
                }
            }
            if(firstidx!=-1 && secondidx!=-1)
                following = (secondidx - firstidx >=6);
        }
        if(!following)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        
    }
    
    return 0;
}