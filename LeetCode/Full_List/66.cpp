class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            digits[i] += carry;
            if(digits[i]<10){
                carry = 0;
                break;
            }
            else{
                carry = digits[i]/10;
                digits[i] %= 10;
            }
        }
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};