#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    bool compare(string a, string b){
        for(int i = 0; i < a.size(); i++){
            if(i >= b.size()) return false;
            if(a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
        return true;
    };
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end(),compare);
        vector<vector<string>> res(searchWord.size());
        //better brute force
        for(int i = 0; i < products.size(); i++)
        {
            int lastMatchPos = 0;
            for(; lastMatchPos < searchWord.size(); lastMatchPos++)
            {
                if(lastMatchPos >= products[i].size() || searchWord[lastMatchPos] != products[i][lastMatchPos]) 
                    break;
            }
            lastMatchPos--;
            for(int id = 0; id <= lastMatchPos; id++)
            {
                if(res[id].size() >= 3) continue;
                res[id].push_back(products[i]);
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