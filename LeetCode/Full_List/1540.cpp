class Solution {
public:
    void debug(vector<int>& arr){
        for(auto& x:arr)
            cout<< x << " ";
        cout<<"\n";
    }
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size())
            return false;
        int n = s.size();
        int times = k/26;
        int rem = k%26;
        vector<int> count(26,times);
        for(int i=0; i<rem; i++)
            count[i]++;
        // debug(count);
        for(int i=0; i<n; i++){
            int x = s[i]-'a';
            int y = t[i]-'a';
            int curr = y-x;
            if(curr==0)
                continue;
            if(curr<0)
                curr += 26;
            curr %= 26;
            if(curr==0)
                curr = 25;
            else
                curr -= 1;
            count[curr]--;
            // cout<<curr<<" ";
            if(count[curr]<0)
                return false;
            
        }
        return true;
    }
};