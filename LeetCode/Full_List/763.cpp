class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_idx(26, 0);
        for(int i = 0; i < S.size(); i++){
            last_idx[S[i]-'a'] = i;
        }
        
        vector<int> results;
        
        int right = -1, left = 0;
        for(int i = 0; i < S.size(); i++){
            right = max(right, last_idx[S[i]-'a']);
            if(i == right) {
                results.push_back(right - left + 1);
                left = i+1;
            }
        }
        return results;
    }
};