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

void prefix_function(const string& pattern, int m, vector<int>& lps){//O(m)
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while(i<m){
        if(pattern[i] == pattern[length]){
            length++;
            lps[i] = length;
            i++;
        }
        else{
            if(length!=0)
                length = lps[length-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return;
}

vector<int> KMP(const string& text, const string& pattern){//O(n+m)
    int m = pattern.size();
    int n = text.size();
    vector<int> lps(m,0);
    prefix_function(pattern,m,lps);
    int i = 0, j = 0;
    vector<int> indices;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            indices.push_back(i-j);
            j = lps[j-1];
        }
        else if(i<n && pattern[j]!=text[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return indices;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}