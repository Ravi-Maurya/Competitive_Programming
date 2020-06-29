class Solution {
public:
    unordered_map<int,string> tens,twentys;
    
    Solution(){
        twentys[0] = "";
        twentys[1] = "One"; twentys[2] = "Two";
        twentys[3] = "Three"; twentys[4] = "Four";
        twentys[5] = "Five"; twentys[6] = "Six";
        twentys[7] = "Seven"; twentys[8] = "Eight";
        twentys[9] = "Nine"; twentys[10] = "Ten";
        twentys[11] = "Eleven"; twentys[12] = "Twelve"; twentys[13] = "Thirteen";
        twentys[14] = "Fourteen"; twentys[15] = "Fifteen"; twentys[16] = "Sixteen";
        twentys[17] = "Seventeen"; twentys[18] = "Eighteen"; twentys[19] = "Nineteen";
        
        tens[2] = "Twenty";tens[3] = "Thirty";tens[4] = "Forty";tens[5] = "Fifty";
        tens[6] = "Sixty";tens[7] = "Seventy";tens[8] = "Eighty";tens[9] = "Ninety";
    }
    
    
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string res = "";
        if(num>=1000000000){
            res += numberToWords(num/1000000000) + " Billion";
            num = num%1000000000;
            if(num)
                res += " ";
        }
        if(num>=1000000){
            res += numberToWords(num/1000000) + " Million";
            num = num%1000000;
            if(num)
                res += " ";
        }
        if(num>=1000){
            res += numberToWords(num/1000) + " Thousand";
            num = num%1000;
            if(num)
                res += " ";
        }
        if(num>=100){
            res += numberToWords(num/100) + " Hundred";
            num = num%100;
            if(num)
                res += " ";
        }
        if(num>=20){
            res += tens[num/10];
            num = num%10;
            if(num)
                res += " ";
        }
        if(num>0)
            res += twentys[num];
        return res;
        
    }
};