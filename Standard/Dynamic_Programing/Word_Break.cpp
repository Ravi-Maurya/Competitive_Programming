#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool recursive(string st, unordered_set<string>& ust){
    if(st.size()==0)
        return true;
    for(int k=1; k<=st.size(); k++){
        if(ust.count(st.substr(0,k)) && recursive(st.substr(k))
            return true;
    }
    return false;
}

bool wordBreak1(string s, unordered_set<string>& ust){//O(size*size)
    int size = s.size();
    if(size==0)
        return true;
    vector<bool> dp(size+1,false);
    for(int i=1; i<=size; i++){
        if(!dp[i] && ust.count(s.substr(0,i)))
            dp[i] = true;
        if(dp[i]){
            if(i==size)
                return true;
            for(int j = i+1; j<=size; j++){
                if(!d[j] && ust.count(s.substr(i,j-1)))
                    dp[j] = true;
                if(dp[j] && j==size)
                    return true;
            }
        }
    }
    return false;
}

bool wordBreak2(string s, unordered_set<string>& ust){//O(size*n) where n is the number of words to be split
    int size = s.size();
    if(size==0)
        return 1;
    vector<bool> dp(size+1,0);
    vector<int> matched_idx;
    matched_idx.push_back(-1);
    for(int i=0; i<size;i++){
        int msize = matched_idx.size();
        int f = 0;
        for(int j=msize-1; j>=0; j--){
            if(ust.count(s.substr(matched_idx[j]+1, i-matched_idx[j]))){
                f = 1;break;
            }
        }
        if(f){
            dp[i] = 1;
            matched_idx.push_back(i);
        }
    }
    return dp[size-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}