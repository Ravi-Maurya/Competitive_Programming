class Solution {
public:
    int myAtoi(string str) {
        int n = str.size()-1;
        int i  =0;
        while(i<=n && str[i]==' ')
            i++;
        while(i<=n && str[n]==' ')
            n--;
        long long int res = 0;
        int sign = 1;
        if(i<=n){
            if(str[i]=='+' || str[i]=='-'){
                sign = (str[i]=='+')? 1:-1;
                i++;
            }
            cout<<i <<" "<< n;
            long long int curr = 0;
            while(i<=n && isdigit(str[i])){
                curr = curr*10 + (str[i++]-'0');
                cout<<curr<<"\n";
                if((curr*sign)>INT_MAX)
                    return INT_MAX;
                if((curr*sign)<INT_MIN)
                    return INT_MIN;
            }
            res = sign*curr;
        }
        return res;
    }
};