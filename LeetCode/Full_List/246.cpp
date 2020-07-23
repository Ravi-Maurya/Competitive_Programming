class Solution {
public:
    bool isStrobogrammatic(string num) {
        string n = "";
        for(auto x: num){
            if(x=='2' || x=='3' || x=='4' || x=='5' || x=='7')
                return false;
            else{
                if(x=='0')
                    n = n + '0';
                else if(x=='1')
                    n = n + '1';
                else if(x=='6')
                    n = n + '9';
                else if(x=='8')
                    n = n + '8';
                else if(x=='9')
                    n = n + '6';
            }
        }
        reverse(n.begin(),n.end());
        return num==n;
    }
};