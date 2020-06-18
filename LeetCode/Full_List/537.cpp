class Solution {
public:
    pair<int,int> convert(string s){
        string real = "", complex = "";
        int i  =0;
        while(s[i]!='+'){
            real += s[i++];
        }
        i++;
        while(s[i]!='i'){
            complex += s[i++];
        }
        return {stoi(real),stoi(complex)};
    }
    string complexNumberMultiply(string a, string b) {
        auto x = convert(a);
        auto y = convert(b);
        string res = to_string((x.first * y.first) - (x.second * y.second));
        res += '+';
        res += to_string(x.first*y.second + y.first*x.second);
        res += 'i';
        return res;
    }
};