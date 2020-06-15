class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> res;
        for(auto t: ops){
            if(t=="+"){
                int b = res.top();res.pop();
                int a = res.top();
                int r = a + b;
                res.push(b);
                res.push(r);
            }
            else if(t=="D"){
                int tmp = res.top();
                res.push(2*tmp);
            }
            else if(t=="C"){
                res.pop();
            }
            else{
                res.push(stoi(t));
            }
        }
        int ans = 0;
        while(!res.empty()){
            ans += res.top();
            res.pop();
        }
        return ans;
    }
};