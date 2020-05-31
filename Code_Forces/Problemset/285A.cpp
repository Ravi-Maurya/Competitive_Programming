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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll max1 = (3*a)/10;
    ll tmp = ((250-c)*a)/250;
    if(max1<tmp)
        max1 = tmp;
    ll max2 = (3*b)/10;
    tmp = ((250-d)*b)/250;
    if(max2<tmp)
        max2 = tmp;
    if(max1 > max2)
        cout<<"Misha\n";
    else if(max1 < max2)
        cout<<"Vasya\n";
    else
        cout<<"Tie\n";
    return 0;
}