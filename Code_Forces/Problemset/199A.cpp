#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    // vector<int> arr(n);
    bool isvalid = true;
    vector<int> count(8,0);
    int groups = n/3;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        count[tmp]++;
        if(tmp==5 || tmp==7)
            isvalid = false;
    }
    if(!isvalid || count[1]!=groups || (count[2]+count[3])!=groups || (count[4]+count[6])!=groups || count[3]>count[6] || count[4]>count[2]){
        cout<<-1<<"\n";
        return 0;
    }
    // vector<vector<int>> res(groups,vector<int>(3,0));
    while(count[4]>0){
        cout<<1<<" "<<2<<" "<<4<<"\n";
        // res.push_back({1,2,4});
        count[4]--;
        count[2]--;
        count[1]--;
    }
    int three = count[3];
    count[6] -= three;
    while(count[6]>0){
        cout<<1<<" "<<2<<" "<<6<<"\n";
        // res.push_back({1,2,6});
        count[6]--;
        count[2]--;
        count[1]--;
    }
    while(count[3]>0){
        cout<<1<<" "<<3<<" "<<6<<"\n";
        // res.push(back({1,3,6}));
        count[3]--;
    }
    return 0;
}