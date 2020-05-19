#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

void bfs(int n){
	queue<pair<long long int, pair<long long int, long long int>>> q;
	long long int numb;
	q.push({4, {1, 0}});
	q.push({7, {0, 1}});
	while(!q.empty()){
		auto p = q.front();q.pop();
		numb = p.first*10+4;
		p.second.first++;
		if(numb>=n && p.second.first==p.second.second){
			cout<<numb;
			return;
		}
		q.push({numb, p.second});
 
		numb = p.first*10+7;
		p.second.first--;
		p.second.second++;
		if(numb>=n && p.second.first==p.second.second){
			cout<<numb;
			return;
		}
		q.push({numb, p.second});
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    bfs(n);
    cout<<"\n";
    return 0;
}