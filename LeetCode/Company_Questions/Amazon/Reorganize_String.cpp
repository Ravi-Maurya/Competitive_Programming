class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26,0);
        int n = S.size();
        for(auto ch:S)
            count[ch-'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i=0; i<26; i++){
            if(count[i]>0){
                if(count[i]>(n+1)/2)
                    return "";
                pq.push({count[i],(char)('a'+i)});
            }
        }
        string res = "";
        while(pq.size()>=2){
            auto ch1 = pq.top(); pq.pop();
            auto ch2 = pq.top(); pq.pop();
            ch1.first -= 1;
            ch2.first -= 1;
            res.push_back(ch1.second);
            res.push_back(ch2.second);
            if(ch1.first>0)
                pq.push(ch1);
            if(ch2.first>0)
                pq.push(ch2);
        }
        if(pq.size())
            res.push_back(pq.top().second);
        return res;
    }
};