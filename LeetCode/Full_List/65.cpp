class Solution {
public:
    bool isNumber(string s) {
        if(s.length() == 0)
            return false;
        int i = 0,n = s.length()-1;
        bool e = false, dot = false, digit = false;
        while(i <= n && s[i] == ' ')
            i++;
        while(n>= i && s[n] == ' ')
            n--;
        if(s[i] == '+' || s[i] == '-')
            i++;
        if(i > n)
            return false;
        for(;i <= n;i++){
	        if(isdigit(s[i])){
		        digit = true;
		        continue;
	        }
	        else if(s[i] == 'e' && digit && i != n && !e){
	            e = true;
		        if(s[i + 1] == '+' || s[i + 1] == '-')
			        if(i == n - 1) return false;
			        else i++;
	        }
	        else if(s[i] == '.' && !dot && !e)  dot = true;
	        else return false;
        }
        return digit;
    }
};