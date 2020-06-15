class Solution {
public:
    bool isvowel(char c){
        if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int l = 0, h = s.size()-1;
        while(l<h){
            while(l<h && !isvowel(s[l]))
                l++;
            while(l<h && !isvowel(s[h]))
                h--;
            if(l<h)
                swap(s[l++],s[h--]);
        }
        return s;
    }
};