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

struct node{
    int x,y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int i = 1;
    vector<node> arr(105);
    while(n--){
        int query,u,v;
        cin>>query>>u>>v;
        if(query==1){
            arr[i].x = u;
            arr[i].y = v;
            i++;
        }
        else{
            vector<bool> visited(i+1,false);
            queue<int> q;
            q.push(u);
            visited[u] = true;
            bool found = false;
            while(!q.empty()){
                u = q.front();q.pop();
                if(u==v){
                    found = true;
                    break;
                }
                for(int v1 = 1; v1<=i; v1++){
                    if(!visited[v1] && ((arr[u].x > arr[v1].x && arr[u].x < arr[v1].y) || (arr[u].y > arr[v1].x && arr[u].y < arr[v1].y))){
                        q.push(v1);
                        visited[v1] = true;
                    }
                }
            }
            if(found)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}