#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
char m[26];
class Solution {

public:
    bool isAlienSorted(vector<string>& words, string order) {
        char x = 'a';
        for(int i=0;i<order.size();i++){
            m[order[i]-'a']=x;
            x++;
        }
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
               words[i][j]=m[words[i][j]-'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}