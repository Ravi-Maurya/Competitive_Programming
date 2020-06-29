
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,string> &a, const pair<int,string> &b) {
            return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
        };
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        for(string s : words) {
            dict[s]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> minheap;
        for(auto& [s,val]: dict){
            minheap.push({val,s});
            if(minheap.size()>k)
                minheap.pop();
        }
        
        vector<string> res(k);
        while(!minheap.empty()){
            k--;
            res[k] = minheap.top().second;
            minheap.pop();
        }
        return res;
    }
};