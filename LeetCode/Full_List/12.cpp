class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mapp;
        mapp[1] = "I";mapp[4]="IV"; mapp[5] = "V";
        mapp[9] = "IX";mapp[10] = "X";mapp[40] = "XL"; mapp[50] = "L";
        mapp[90] = "XC";mapp[100] = "C";mapp[400]="CD";mapp[500] = "D";
        mapp[900] = "CM";mapp[1000] = "M";
        vector<int> Int = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        int n = 13;
        int idx = n-1;
        string res = "";
        while(num){
            while(Int[idx]>num)
                idx--;
            num -= Int[idx];
            res += mapp[Int[idx]];
        }
        return res;
    }
};