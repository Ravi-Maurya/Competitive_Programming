class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "##";
        int n = a+b+c;
        priority_queue<pair<int,int>> pq;
        if(a>0)
            pq.push({a,0});
        if(b>0)
            pq.push({b,1});
        if(c>0)
            pq.push({c,2});
        while(!pq.empty()){
            auto curr = pq.top();pq.pop();
            char ch = curr.second + 'a';
            if(res[res.size()-1] == ch && res[res.size()-2] == ch){
                if(pq.empty())
                    return res.substr(2);
                auto curr2 = pq.top();pq.pop();
                pq.push(curr);
                ch = curr2.second + 'a';
                res += ch;
                curr2.first -= 1;
                if(curr2.first>0)
                    pq.push(curr2);
            }
            else{
                res += ch;
                curr.first -= 1;
                if(curr.first>0)
                    pq.push(curr);
            }
        }
        return res.substr(2);
    }
};