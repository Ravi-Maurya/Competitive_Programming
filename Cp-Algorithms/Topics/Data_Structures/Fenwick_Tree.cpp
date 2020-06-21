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

class BIT{
    private:
    vector<int> bit;
    int n;
    public:
    BIT(vector<int>& arr){
        n = arr.size();
        bit.clear();
        bit.resize(n,0);
        for(int i=0; i<n; i++)
            update(i,arr[i]);
    }

    void update(int idx, int val){
        while(idx<n){
            bit[idx] += val;
            idx = idx|(idx+1);
        }
        return;
    }
    int query1(int idx){// gives [0,i] for [l,r] = query(r)-query(l-1);
        int sum = 0;
        while(idx>=0){
            sum += bit[idx];
            idx = (idx&(idx+1)) - 1;
        }
        return sum;
    }

    int query2(int l, int r){
        return query1(r) - query1(l-1);
    }
};

class BIT2D{
    private:
    vector<vector<int>> bit;
    int n, m;
    public:
    BIT2D(vector<vector<int>>& matrix){
        n = matrix.size();
        m = matrix[0].size();
        bit.resize(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
            for(int j=0; j<m;j++)
                update(i,j,matrix[i][j]);
    }

    void update(int x, int y, int val){
        for(int i=x; i<n; i = i | (i+1)){
            for(int j=y; j<m; j = j | (j+1)){
                bit[i][j] += val;
            }
        }
    }

    int query1(int x, int y){
        int res = 0;
        for(int i=x; i>=0; i = (i&(i+1)) - 1){
            for(int j=y; j>=0; j = (j&(j+1)) - 1){
                res += bit[i][j];
            }
        }
        return res;
    }

    int query2(int x1, int y1, int x2, int y2){
        int v1 = query1(x2,y2);
        int v2 = query1(x1-1,y1-1);
        int v3 = query1(x1-1,y2);
        int v4 = query1(x2,y1-1);
        return (v1 + v2 - v3 - v4);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                {5, 3, 8, 1},
                                {4, 6, 7, 5},
                                {2, 4, 8, 9}};
    auto bt = BIT2D(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++)
            cout << bt.query2(i,j,i,j) << " ";
        cout<< "\n";
    }
    return 0;
}