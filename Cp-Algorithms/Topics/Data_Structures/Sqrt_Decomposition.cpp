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

class Mo{
    private:
    vector<int> sum,arr;
    int len,n;
    public:
    Mo(vector<int>& arrr){
        arr.clear();
        sum.clear();
        arr = arrr;
        n = arr.size();
        len = (int)sqrt(n + .0) + 1;
        sum.resize(len,0);
        for(int i=0; i<n; i++)
            sum[i/len] += arr[i];
    }

    int query(int l, int r){
        int res = 0;
        for(int i=l; i<=r; ){
            if(i%len == 0 && i+len-1 <=r){
                res += sum[i/len];
                i += len;
            }
            else{
                res += arr[i];
                i++;
            }
        }
        return res;
    }

    void update(int idx, int val){
        int change = val - arr[idx];
        arr[idx] = val;
        sum[idx/len] += change;
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}