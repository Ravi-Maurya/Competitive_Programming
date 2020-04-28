class Solution {
    #define ABC "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz"
    #define ABC_SIZE 62
    #define PREFIX "http://tinyurl.com/"
    #define LENGTH 7
    
    unordered_map<string, string> map;
    int index = 0;
    
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str (LENGTH, 0);
        int num = index++;
        for (int i = LENGTH - 1; i >= 0; --i) {
            str[i] = ABC[num % ABC_SIZE];
            num /= ABC_SIZE;
        }
        map[str] = longUrl;
        return PREFIX + str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.size() - LENGTH);
        return map[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));