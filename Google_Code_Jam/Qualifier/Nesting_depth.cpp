#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        string num;
        cin>>num;
        int n = num.size();
        int brackets = 0;
        string ans = "";
        for(int i=0;i<n;i++){
            int k = num[i]-'0';
            if(k==brackets){
                ans += num[i];
                continue;
            }
            else if(k>brackets){
                while(brackets!=k){
                    ans += '(';
                    brackets++;
                }
                ans += num[i];
            }
            else{
                while(brackets!=k){
                    ans += ')';
                    brackets--;
                }
                ans += num[i];
            }
        }
        while(brackets--){
            ans += ')';
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;
    }
    return 0;
}