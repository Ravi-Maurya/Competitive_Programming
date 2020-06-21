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

// min stack can pe prepared by pair<int,int> storing (origial,minimum till now) O(n) space O(1) other operations

// queue minmum
class MinQueue1{// always makes sure that q.front()is minimum and always maintain this order
    // can also use for Max Queue element 
    // for dublicates its better to store indexes of array hen using
    public:
    deque<int> dq;
    MinQueue1(){
        dq.clear();
    }

    int getmin(){
        return dq.front();
    }

    void addelemnt(int n){
        while(!dq.empty() && dq.back()>n)
            dq.pop_back();
        dq.push_back(n);
        return;
    }

    void remove(int n){
        if(!dq.empty() && dq.front()==n)
            dq.pop_front();
        return;
    }
};

class SparseTable{
    public:
    vector<vector<int>> table;
    vector<int> arr;
    int n;
    SparseTable(vector<int> input){
        n = input.size()+5;
        table.clear();
        table.reserve(n,vector<int>(n));
    }

    void build(){//O(nlogn)
        for(int i=0;i<n; i++)
            table[i][0] = arr[i];
        for(int j=1; (1<<j) <= n; j++){
            for(int i=0; i+(1<<j)-1 < n; i++ ){
                if(table[i][j-1] < table[i+(1<<(j-1))][j-1])
                    table[i][j] = table[i][j-1];
                else
                    table[i][j] = table[i+(1<<(j-1))][j-1];
            }
        }
    }

    int query(int l, int r){//O(1)
        int j = (int)log2(r-l+1);
        if(table[l][j]<=table[r - (1<<j) + 1][j])
            return dp[l][j];
        return table[r - (1<<j) + 1][j];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}