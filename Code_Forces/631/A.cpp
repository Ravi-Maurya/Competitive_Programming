#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        set<int> A;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            A.insert(tmp);
        }
        vector<int> res;
        for(auto& i:A)
            res.push_back(i);
        int k = res.size();
        int pos = -1;
        for(int i=k-1;i>=0;i--){
            if(res[i]<=x+(i+1))
                break;
            pos = i;
        }
        if(pos==-1)
            cout<<(x+k)<<endl;
        else{
            if(pos==0)
                cout<<x<<endl;
            else{
                if(res[pos]-(x+pos)==1)
                    cout<<res[pos]<<endl;
                else
                    cout<<x+pos<<endl;
            }
        }
    }
    return 0;
}