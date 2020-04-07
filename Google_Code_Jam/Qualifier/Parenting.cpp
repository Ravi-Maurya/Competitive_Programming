#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test =1;test<=t;test++){
        int n;
        cin>>n;
        vector<string> res(n,"N");
        multimap<pair<int,int>,int> mapp;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            mapp.insert(make_pair(make_pair(x,y),i));
        }

        pair<int,int> c = {-1,-1}, j = {-1,-1};
        bool impossible = false;
        auto it = mapp.begin();
        while(it!=mapp.end()){
            if((c.first==-1) || (c.second <= (it->first).first)){
                c = it->first;
                res[it->second] = "C";
                it++;
            }
            else if ((j.first==-1) || j.second <= (it->first).first){
                j = it->first;
                res[it->second] = "J";
                it++;
            }
            else{
                impossible = true;
                break;
            }
        }
        if(impossible == true){
            cout<<"Case #"<<test<<": "<<"IMPOSSIBLE"<<endl;
            impossible = false;
        }
        else{
            string ans = "";
            for(int i=0;i<n;i++)
                ans += res[i];
            cout<<"Case #"<<test<<": "<<ans<<endl;
        }

    }
    return 0;
}