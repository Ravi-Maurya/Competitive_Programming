#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

// #define ll long long int
// #define pll pair<ll,ll> 
// #define pls pair<ll,string>
// #define psl pair<string,ll>
// #define plc pair<ll,char>
// #define pcl pair<char,ll>
// #define pss pair<string,string>
// #define maxheap(type) priority_queue<type>
// #define minheap(type) priority_queue<type,vector<type>,greater<type>>
// #define setbits(x) __builtin_popcountll(x)
// #define zerobits(x) __builtin_ctzll(x)
// #define mod 1000000007
// #define inf 1e18
// #define precise(x,y) fixed<<setprecision(y)<<x
// #define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
// #define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
// #define rep(n) for(auto i=0; i<n; i++)


int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	char G = 'G';
	char B = 'B';
	cin >> N >> M;
 
	if (N < M) {
		swap(G,B);
		swap(N,M);
	}
 
	for (int i=0; i<M; i++)
		cout << B << G;
	for (int i=0; i<N-M; i++)
		cout << B;
 
	return 0;
}