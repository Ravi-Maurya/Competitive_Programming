class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> arr(10,0),check(10,0);
        for(auto x: secret)
            arr[x-'0']++;
        int a = 0, b = 0, n = guess.size();
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]){
                a++;
                arr[secret[i]-'0']--;
            }
            else{
                check[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            if(check[i]!=0){
                if(arr[i]!=0)
                    b += min(check[i],arr[i]);
            }
        }
        string res = to_string(a) + "A" + to_string(b) + "B";
        return res;
    }
};