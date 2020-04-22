#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    int find(vector<int>&v, int x){
        if(v[x]==x)return x;
        return find(v, v[x]) ;
    }
    void uniong(vector<int>&v, int x, int y){
        int fx=find(v, x); int fy=find(v, y);
        if(fx==fy)cnt++;   // cnt == total redundant edges that makes cycle in graph
        if(fx>fy) 
            v[fx]=fy;
        else{
           v[fy]=fx ;
        }
    }
    int cnt;
    int makeConnected(int key, vector<vector<int>>& con) {
        int n=con.size(); if(n<key-1)return -1; //atleast n-1 edges to make a graph of n nodes connected
        cnt=0;
        vector<int> v(key, 0); for(int i=0;i<key;i++) v[i]=i ;
        
        for(int i=0; i<n; i++){
            uniong(v, con[i][0], con[i][1])    ;
        } 
        int con_so_far=n-cnt+1; int cnt_left=key-con_so_far;  
        if(cnt_left<=cnt)return cnt_left ;
        else
            return -1;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}