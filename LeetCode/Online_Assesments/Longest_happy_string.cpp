#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct mycomp{
    bool operator()(const pair<char,int>& a, const pair<char,int>& b){
        return a.second < b.second; 
    }
};

string solve(int a, int b, int c){
    if(a==0 && b==0 && c==0)
        return "";
    priority_queue<pair<char,int>, vector<pair<char,int>>, mycomp> pq;
    if(a>0)
        pq.push({'a',a});
    if(b>0)
        pq.push({'b',b});
    if(c>0)
        pq.push({'c',c});
    string res = "";
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        if((res == "")  ||  (res[res.size()-1]!=curr.first)){
            if(curr.second>=2){
                res += curr.first;
                res += curr.first;
                curr.second -= 2;
            }
            else if(curr.second>=1){
                res += curr.first;
                curr.second -= 1;
            }
            if(curr.second>0)
                pq.push(curr);  
        }
        else if(res[res.size()-1]==curr.first){
            if(pq.empty())
                break;
            auto curr2 = pq.top();
            pq.pop();
            res += curr2.first;
            curr2.second -= 1;
            if(curr2.second>0)
                pq.push(curr2);
            pq.push(curr);
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}