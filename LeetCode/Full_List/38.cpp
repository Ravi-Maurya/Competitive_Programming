class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "";
        if(n==1)
            return "1";
        n--;
        string num = "1";
        while(n--){
            int j = 0;
            int count = 0;
            string res = "";
            while(j<num.size()){
                count = 1;
                while(j<num.size()-1 && num[j]==num[j+1]){
                    j++;
                    count++;
                }
                res += to_string(count) + num[j];
                j++;
            }
            num = res;
        }
        return num;
    }
};


class Solution {
public:
    
    string countAndSayNext(const string& current) {
        stringstream ss;
        int count = -1;
        
        char last_char; 
        for(char c : current) {
            if(count == -1) {
                last_char = c;
                count = 1;
                continue;
            }
            if(c == last_char) {
                count++;
                continue;
            }
            ss << count << last_char;
            last_char = c;
            count = 1;
        }
        ss << count << last_char;
        
        return ss.str();
    }
    
    
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; ++i) {
            result = countAndSayNext(result);
        }
        
        return result;
    }
};