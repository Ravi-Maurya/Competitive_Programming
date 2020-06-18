class Solution {
    #define ABC "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz"
    #define ABC_SIZE 62
    #define PREFIX "http://tinyurl.com/"
    #define LENGTH 7
    unordered_map<string, string> ump;
    int index = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string st(LENGTH,0);
        int n = index++;
        for(int i=LENGTH-1; i>=0; i--){
            st[i] = ABC[n%ABC_SIZE];
            n /= ABC_SIZE;
        }
        ump[st] = longUrl;
        return PREFIX+st;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.size()-LENGTH);
        return ump[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));