#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<string> substring_with_size_k(string A, int K) {
    unordered_map<char,int> alphabets;
    int n = A.size(),i=0,j=0;
    vector<string> res;
    while(i<n){
        if(alphabets.find(A[i])==alphabets.end())
            alphabets[A[i]] = -1;
        if(j<=alphabets[A[i]])
            j = alphabets[A[i]]+1;
        alphabets[A[i]] = i;
        i+=1;
        if(i-j == K)
            res.push_back(A.substr(j,i-j));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}