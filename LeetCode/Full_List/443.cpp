class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        for(int r = 0; r<chars.size(); r++){
            if(r+1 == chars.size() || chars[r+1]!=chars[r]){
                chars[j++] = chars[i];
                if(r>i){
                    for(auto ch: to_string(r-i+1))
                        chars[j++] = ch;
                }
                i = r+1;
            }
        }
        return j;
    }
};