class Solution {
public:
    int myAtoi(string str) {
        long long int res = 0;
        int sign = 1;
        int i = 0;
        int n = str.size();
        while(i<n && str[i]==' ')
            i++;
        if(str[i]=='-'){
            sign = -1;
            i++;
        }
        else if(str[i]=='+')
            i++;
        
        while(i<n && isdigit(str[i])){
            res = res*10 + (str[i++]-'0');
            if(INT_MIN>sign*res)
                return INT_MIN;
            else if(sign*res>INT_MAX)
                return INT_MAX;
        }
        return sign*res;
    }
};