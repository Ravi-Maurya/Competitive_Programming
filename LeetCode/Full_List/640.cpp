class Solution {
public:
    string solveEquation(string equation) {
        char sign = '+',prev = '+';
        int tmp_val = 0;
        bool equals = false;
        int x = 0, val = 0;
        int i = 0;
        int n = equation.size();
        while(i<n){
            char ch = equation[i];
            if(isdigit(ch)){
                tmp_val = tmp_val*10 + (ch-'0');
            }
            else if(ch=='x'){
                if(prev=='+'||prev=='-' || prev=='='){
                    tmp_val = 1;
                }
                if(equals){
                    x -= ((sign=='+')?1:-1)*tmp_val;
                }
                else{
                    x += ((sign=='+')?1:-1)*tmp_val;
                }
                sign = '+';
                tmp_val = 0;
            }
            else if(ch=='+' || ch =='-'){
                if(equals){
                    val += ((sign=='+')?1:-1)*tmp_val;
                }
                else{
                    val -= ((sign=='+')?1:-1)*tmp_val;
                }
                sign = ch;
                tmp_val = 0;
            }
            else if(ch=='='){
                if(equals){
                    val += ((sign=='+')?1:-1)*tmp_val;
                }
                else{
                    val -= ((sign=='+')?1:-1)*tmp_val;
                }
                sign = '+';
                tmp_val = 0;
                equals = true;
            }
            if(i==n-1){
                if(equals){
                    val += ((sign=='+')?1:-1)*tmp_val;
                }
                else{
                    val -= ((sign=='+')?1:-1)*tmp_val;
                }
            }
            prev = ch;
            i++;
        }
        if(x==0 && val==0){
            return "Infinite solutions";
        }
        if(x==0){
            return "No solution";
        }
        val = val/x;
        return "x="+to_string(val);
        
    }
};