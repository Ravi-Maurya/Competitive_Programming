#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int word_count = words.size();
        if(word_count==0)
            return res;
        int k = words[0].size();
        int n = s.size();
        if(k==0 || k*word_count>n)
            return res;
        unordered_map<string,int> ump;
        unordered_map<string,int> tmp;
        for(auto word: words)
            ump[word]++;
        for(int i=0; i<(n - (word_count*k) + 1); i++){
            tmp.clear();
            int num = 0;
            while(num<word_count){
                auto word = s.substr(i+num*k, k );
                if(ump.find(word)!=ump.end()){
                    tmp[word]++;
                    if(ump[word]<tmp[word])
                        break;
                }
                else
                    break;
                
                num++;
            }
            if(num==word_count)
                res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int word_count = words.size();
        if(word_count==0)
            return res;
        int k = words[0].size();
        int n = s.size();
        if(k==0 || k*word_count>n)
            return res;
        unordered_map<string,int> ump;
        unordered_map<string,int> tmp;
        for(auto word: words)
            ump[word]++;
        for(int i=0; i<k; ++i){
            int left = i, count = 0;
            tmp.clear();
            for(int j=i; j<=n-k; j+=k){
                string word = s.substr(j,k);
                if(ump.count(word)){
                    tmp[word]++;
                    if(tmp[word]<=ump[word])
                        count++;
                    else{
                        while(tmp[word]>ump[word]){
                            string wrd = s.substr(left,k);
                            tmp[wrd]--;
                            if(tmp[wrd]<ump[wrd])
                                count--;
                            left += k;
                        }
                    }
                    if(count == word_count){
                        res.push_back(left);
                        tmp[s.substr(left,k)]--;
                        count--;
                        left += k;
                    }
                }
                else{
                    tmp.clear();
                    count = 0;
                    left = j+k;
                }
            }
        }
        return res;
    }
};