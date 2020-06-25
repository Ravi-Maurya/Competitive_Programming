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
    int t;
    cin>>t;
    char fill[3] = {'a','b','c'};
    while(t--){
        string s;
        cin>>s;
        int n = s.size(),i=0;
        while(i<n){
            if(s[i]=='?'){
                char prev = '#',next= '.';
                if(i!=0)
                    prev = s[i-1];
                if(i<n-1)
                    next = s[i+1];
                for(auto& ch: fill)
                    if(ch!=prev && ch!=next){
                        s[i] = ch;
                        break;
                    }
            }
            else
                i++;
        }
        bool flag = true;
        for(int i=0; i<n-1; i++)
            if(s[i]==s[i+1]){
                flag = false;
                break;
            }
        if(flag)
            cout<< s << "\n";
        else
            cout<< -1 << "\n";
    }
    return 0;
}