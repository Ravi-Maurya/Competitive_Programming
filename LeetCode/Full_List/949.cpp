class Solution {
public:
    int get_int(vector<int>& A){
        int x = 0;
        for(int a: A){
            x = x*10 + a;
        }
        return x;
    }
    
    string get_string(int x){
        string s = to_string(x);
        int n = s.size();
        string res = "";
        if(n==4){
            res += s[0];
            res += s[1];
            res += ':';
            res += s[2];
            res += s[3];
        }
        else if(n==3){
            res += '0';
            res += s[0];
            res += ':';
            res += s[1];
            res += s[2];
        }
        else if(n==2){
            res += '0';
            res += '0';
            res += ':';
            res += s[0];
            res += s[1];
        }
        else{
            res += '0';
            res += '0';
            res += ':';
            res += '0';
            res += s[0];
        }
        return res;
    }
    bool check(int x){
        int hour = x/100;
        int min = x%100;
        return (hour<=23 && hour >=0 && min<=59 && min>=00);
    }
    string largestTimeFromDigits(vector<int>& A) {
        int res = 0;
        sort(A.begin(),A.end());
        bool flag = false;
        do{
            int x = get_int(A);
            if(res<=x && check(x)){
                flag = true;
                res = x;
            }
        }while(next_permutation(A.begin(), A.end()));
        if(!flag)
            return "";
        return get_string(res);
    }
};