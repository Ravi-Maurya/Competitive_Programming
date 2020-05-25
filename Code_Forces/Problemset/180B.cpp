#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

void change(ll& dx, ll& dy, char ch){
    if((ch=='N' || ch=='S') && dy!=0){
        ll d = dy - ((ch=='N')?1:-1);
        if(abs(d)<abs(dy))
            dy = d;
    }
    else if((ch=='E' || ch=='W') && dx!=0){
        ll d = dx - ((ch=='E')?1:-1);
        if(abs(d)<abs(dx))
            dx = d;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll t, sx, sy, ex, ey;
    cin>>t>>sx>>sy>>ex>>ey;
    ll dx = ex-sx;
    ll dy = ey-sy;
    string s;
    cin>>s;
    for(int i=0; i<s.size();i++){
        if(dx==0 && dy==0){
            cout<<i<<"\n";
            return 0;
        }
        char ch = s[i];
        change(dx,dy,ch);
    }
    if(dx==0 && dy==0)
        cout<<s.size()<<"\n";
    else
        cout<<-1<<"\n";
    return 0;
}