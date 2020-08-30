class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for(int i = 0; i < A.size(); i++){
           auto idx = max_element(A.begin(), A.end() - i);
           res.push_back(idx  - A.begin() + 1);  
           res.push_back(A.size() - i);
           reverse(A.begin(), idx+1);
           reverse(A.begin(), A.end() - i);
        }
        return res;
    }
};