#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowels({'A','E','I','O','U','a','e','i','o','u'});
        stringstream ss(S);
        string word;
        string res = "";
        int t = 1;
        while(ss>>word){
            char first = word[0];
            if(vowels.find(first)!=vowels.end())
                res += word;
            else{
                res += word.substr(1);
                res += word[0];
            }
            res += "ma";
            for(int i=0; i<t; i++)
                res += "a";
            t++;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}