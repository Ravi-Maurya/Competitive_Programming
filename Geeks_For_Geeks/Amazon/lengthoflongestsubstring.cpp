#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int lengthOfLongestSubstring(string A) {
    unordered_map<char,int> alphabets;
    int n = A.size(),i=0,j=0,res=0;
    while(i<n){
        if(alphabets.find(A[i])==alphabets.end())
            alphabets[A[i]] = -1;
        if(j<=alphabets[A[i]])
            j = alphabets[A[i]]+1;
        alphabets[A[i]] = i;
        i+=1;
        res = max(res,i-j);
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        string s;
        cin>>s;
        cout<<lengthOfLongestSubstring(s)<<"\n";
    }
    return 0;
}