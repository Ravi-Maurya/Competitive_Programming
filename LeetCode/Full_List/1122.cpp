class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> stats(1001,0);
        
        for (int i = 0; i < arr1.size(); ++i) 
            ++stats[arr1[i]];
        
        int cur = 0;
        for (int i = 0; i < arr2.size(); ++i)
            if (stats[arr2[i]] != 0) {
                for (int j = 0; j < stats[arr2[i]]; ++j)
                    arr1[cur++] = arr2[i];
                stats[arr2[i]] = 0;
            }
    
        for (int i = 0; i < 1001; ++i)
            if (stats[i] != 0)
                for (int j = 0; j < stats[i]; ++j)
                    arr1[cur++] = i;

        return arr1;
    }
};