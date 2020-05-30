#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,int> ump;
    for(int i=0;i<n; i++){
        int t;
        cin>>t;
        ump[t]++;
    }
    if(!ump.count(0)){
        cout<<-1<<"\n";
        return 0;
    }
    if(!ump.count(5) || (ump[5]<9)){
        cout<<0<<"\n";
        return 0;
    }
    int count_5 = ump[5]/9;
    int count_0 = ump[0];
    while(count_5--){
        for(int i=0;i<9;i++)
            cout<<5;
    }
    while(count_0--)
        cout<<0;
    cout<<"\n";
    return 0;
}