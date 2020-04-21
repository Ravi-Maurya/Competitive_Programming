#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef pair<string, int> PAIR;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        for(string s : words) {
            dict[s]++;
        }
        struct cmp {
            bool operator()(const PAIR &a, const PAIR &b) {
                return (a.second == b.second) ? 
                    (a.first > b.first) : 
                    (a.second < b.second);
            };
        };
        priority_queue<PAIR, vector<PAIR>, cmp> pq(dict.begin(), dict.end());
        vector<string> res;
        while (!pq.empty() && res.size() < k) {
            PAIR top = pq.top();
            res.push_back(top.first);
            pq.pop();
        }
        return res;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}