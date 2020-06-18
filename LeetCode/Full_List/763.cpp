class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> ump;
        int n = S.size();
        for(int i = 0; i<n; i++){
            ump[S[i]] = i;
        }
        vector<int> res;
        int left = -1;
        int right = -1;
        for(int i=0;i<n; i++){
            right = max(right,ump[S[i]]);
            if(right==i){
                res.push_back(right-left);
                left = i;
            }
        }
        return res;
    }
};