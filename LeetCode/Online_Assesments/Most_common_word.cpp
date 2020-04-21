#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph += ".";
        unordered_set<string> ban;
        for(auto s: banned)
            ban.insert(s);
        unordered_map<string,int> count;
        string res="";
        int freq = 0;
        string word = "";
        for(char& c: paragraph){
            if(isalpha(c))
                word += tolower(c);
            else if(word.size()>0){
                if(ban.find(word)==ban.end()){
                    count[word]++;
                    if(count[word]>freq){
                        res = word;
                        freq = count[word];
                    }
                }
                word = "";
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