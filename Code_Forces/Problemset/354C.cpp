#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll i,j,k,n,m,a,b;
    cin>>n>>k;
    string s;
    cin>>s;
    ll len=0,ind=0;
	a=0,b=0;
	for(i=0;i<n;i++){
		if(s[i]=='a') a++;
		else b++;
		
		if(min(a,b)>k){
			if(s[ind++]=='a') a--;
			else b--;
		}
		else
			len=max(len,a+b);
	}
	cout<<len<<"\n";
    return 0;
}