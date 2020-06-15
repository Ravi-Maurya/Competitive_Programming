class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26,-1);
        for(auto ch: s)
            arr[ch-'a']++;
        int n = s.size();
        for(int i=0;i<n;i++){
            auto ch = s[i];
            if(arr[ch-'a']==0)
                return i;
        }
        return -1;
    }
};