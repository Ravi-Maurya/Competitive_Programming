#include<bits/stdc++.h>
using namespace std;

class Solution{
    unordered_map<string,vector<int>> word_to_idx;
    public:
    Solution(vector<string> words){
        word_to_idx.clear();
        for(int i=0; i<words.size(); i++)
            word_to_idx[words[i]].push_back(i);
    }

    int shortest(string w1, string w2){
        vector<int> idx1 = word_to_idx[w1], idx2 = word_to_idx[w2];
        int n1 = idx1.size(), n2 = idx2.size();
        int i=0, j=0, global_min_diff = INT_MAX, curr_min_diff;
        while(i<n1 && j<n2){
            curr_min_diff = abs(idx1[i]-idx2[j]);
            global_min_diff = min(global_min_diff, curr_min_diff);
            if(global_min_diff == 0)
                break;
            if(idx1[i]>idx2[j])
                j++;
            else
                i++;
        }
        return global_min_diff;
    }
};