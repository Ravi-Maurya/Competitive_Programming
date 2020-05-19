#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// https://codeforces.com/problemset/problem/489/C
void findSmallest(int m, int s){
    if(!s){
        if(m==1){
            cout<<0<<" ";
            return;
        }
        cout<<-1<<" ";
        return;
    }
    if(s>9*m){
        cout<<-1<<" ";
        return;
    }
    int res[m];
    s -= 1;
    for(int i=m-1; i>0; i--){
        if(s>9){
            res[i] = 9;
            s -= 9;
        }
        else{
            res[i] = s;
            s = 0;
        }
    }
    res[0] = s+1;
    for(int i=0; i<m; i++)
        cout<<res[i];
    cout<<" ";
    return;
}

void findLargest(int m, int s){
    if(!s){
        if(m==1){
            cout<<0<<"\n";
            return;
        }
        cout<<-1<<"\n";
        return;
    }
    if(s>9*m){
        cout<<-1<<"\n";
        return;
    }
    int res[m];
    for(int i=0;i<m;i++){
        if(s>9){
            res[i] = 9;
            s -= 9;
        }
        else{
            res[i] = s;
            s = 0;
        }
    }
    for(int i=0;i<m;i++)
        cout<<res[i];
    cout<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int m, s;
    cin>>m>>s;
    findSmallest(m,s);
    findLargest(m,s);
    return 0;
}