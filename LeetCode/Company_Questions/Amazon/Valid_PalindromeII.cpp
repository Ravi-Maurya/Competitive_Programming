#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Solution {
public:
    bool isPal(string& s, int i, int j){
        for(int k=i;k<=i+(j-i)/2;k++)
            if(s[k]!=s[j-k+i])
                return false;
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++)
            if(s[i]!=s[n-i-1]){
                int j = n-i-1;
                return (isPal(s,i+1,j) || isPal(s,i,j-1));
            }
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}