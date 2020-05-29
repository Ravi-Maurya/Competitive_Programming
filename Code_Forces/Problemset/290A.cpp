#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int r,c;
    cin>>r>>c;
    string tmp1 = "", tmp2 = "", tmp3 = "";
    for(int i=0;i<c; i++){
        tmp1 += '#';
        tmp2 += ((i==0)?'#':'.');
        tmp3 += ((i==c-1)?'#':'.');
    }
    vector<string> arr;
    arr.push_back(tmp1);
    arr.push_back(tmp3);
    arr.push_back(tmp1);
    arr.push_back(tmp2);
    for(int i=0; i<r; i++){
        cout<<arr[i%4]<<"\n";
    }
    return 0;
}