#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26,-1);
        for(int i=0; i<s.size(); i++){
            last_index[s[i]-'a'] = i;
        }
        vector<int> res;
        int j=0,curr_start = 0;
        for(int i=0; i<s.size(); i++){
            j = max(j,last_index[s[i]-'a']);
            if(i==j){
                res.push_back(i-curr_start+1);
                curr_start = i+1;
            }
        }
        return res;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}