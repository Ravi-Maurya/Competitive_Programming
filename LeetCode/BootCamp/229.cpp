class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> hash(10,0);
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i])
                a++;
            else
                hash[secret[i]-'0']++;
        }
        for(int i=0; i<secret.size(); i++){
            if(hash[guess[i]-'0']>0 && guess[i]!=secret[i]){
                b++;
                hash[guess[i]-'0']--;
            }
        }
        string res = to_string(a) + 'A' + to_string(b) + 'B';
        return res;
    }
};