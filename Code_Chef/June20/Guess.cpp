#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

void solve(ll st1, ll en1, ll st2, ll en2){
    if(st1<=en1 && st2<=en2){
        ll mid = st1 + (ll)((en2 - st1)*0.5);
        ll mid2,mid3;
        char x,x2,x3,x4;
        cout << mid << endl;
        cin >> x;
        if(x == 'E')
            return;
        if(x == 'G'){
            ll count = 0;
            x2 = 'L';
            while(st1<=en1 && st2<=en2){
                mid2 = st1 + (ll)((en1 - st1)*0.67);
                mid3 = st2 + (ll)((en2 - st2)*0.33);
                cout << mid2 << endl;
                cin >> x3;
                if(x3 == 'E')
                    return;
                else if((x3=='G') && (count == 0)){
                    solve(mid2+1,en1,st2,en2);
                    return;
                }
                count = 1;
                if(x3=='L' && x2=='G')
                    en1 = mid2-1;
                if(x3==x2 && x3=='G'){
                    st1 = mid2+1;
                    solve(st1,en1,st2,en2);
                    return;
                }
                cout << mid3 << endl;
                cin >> x4;
                x2 = x4;
                if(x4 == 'E')
                    return;
                else if(x3==x4){
                    if(x3=='L')
                        en2 = mid3-1;
                    else
                        st1 = mid2+1;
                    solve(st1,en1,st2,en2);
                    return;
                }
                else if(x3=='L' && x4=='G'){
                    en1 = mid2-1;
                    st2 = mid3+1;
                }
            }
        }
        else{
            ll count = 0;
            x2 = 'G';
            while(st1<=en1 && st2<=en2){
                mid2 = st1 + (ll)((en1 - st1)*0.67);
                mid3 = st2 + (ll)((en2 - st2)*0.33);
                cout << mid3 << endl;
                cin >> x3;
                if(x3 == 'E')
                    return;
                else if((x3=='L') && (count == 0)){
                    solve(st1,en1,st2,mid3-1);
                    return;
                }
                count = 1;
                if(x3=='G' && x2=='L')
                    st2 = mid3+1;
                if(x3==x2 && x3=='L'){
                    en2 = mid3-1;
                    solve(st1,en1,st2,en2);
                    return;
                }
                cout << mid2 << endl;
                cin >> x4;
                x2 = x4;
                if(x4 == 'E')
                    return;
                else if(x3==x4){
                    if(x3=='G')
                        st1 = mid2+1;
                    else
                        en2 = mid3-1;
                    solve(st1,en1,st2,en2);
                    return;
                }
                else if(x3=='G' && x4=='L'){
                    en1 = mid2-1;
                    st2 = mid3+1;
                }
            }
        }
    }
    if(st1>en1 && st2<=en2){
        ll m = st2 + (ll)((en2-st2)*0.5);
        solve(st2,m,m,en2);
        return;
    }
    else if(st2>en2 && st1<=en1){
        ll m = st1 + (ll)((en1-st1)*0.5);
        solve(st1,m,m,en1);
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    ll m = (ll)(n*0.5);
    solve(1,m,m,n);
    return 0;
}