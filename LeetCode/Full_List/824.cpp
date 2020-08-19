class Solution {
public:
    string toGoatLatin(string S) {
        string res = "", word;
        stringstream SS(S);
        string bc = "a";
        while(SS>>word){
            char ch = tolower(word[0]);
            string t = "";
            if(ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u'){
                t += word;
            }
            else{
                t += word.substr(1);
                t += word[0];
            }
            t += "ma";
            res += t;
            res += bc;
            res += ' ';
            bc += 'a';
        }
        res.pop_back();
        return res;
    }
};