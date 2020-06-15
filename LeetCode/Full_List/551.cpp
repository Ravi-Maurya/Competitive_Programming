class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int i = 0, n = s.size();
        while(i<n){
            int count = 0;
            while(i<n && s[i]=='L'){
                i++;
                count++;
            }
            if(count>2)
                return false;
            if(i<n && s[i]=='A')
                a++;
            if(a>1)
                return false;
            i++;
        }
        return true;
    }
};