class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n==0)
            return 0;
        int prev = 0;
        for(int i = 0; i<n;i++){
            if(citations[i]>=(n-i) && (n-i)>=prev){
                return n-i;
            }
            prev = citations[i];
        }
        return 0;
    }
};