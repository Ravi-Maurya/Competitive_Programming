class Solution {
public:
    vector<string> fullJustify(vector<string>& A, int B) {
        vector<string> res;
        short int k = 0, ls = 0;
        for (short int i = 0; i<A.size(); i+=k){
            k = ls = 0;
            while (i+k<A.size() && ls + k + A[i+k].size() <= B){
                ls += A[i+k].size();
                ++k;
            }
            string tmp = A[i];
            for (int j = 0; j < k - 1; j++) {
                if (i + k >= A.size()) tmp += " ";
                else tmp += string((B - ls) / (k - 1) + (j < (B - ls) % (k - 1)), ' ');
                tmp += A[i+j+1];
            }
            tmp += string(B - tmp.size(), ' ');
            res.emplace_back(tmp);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int width = 0;
        int left = 0;
        vector<string> result;
        for (int i = 0; i < words.size(); ++i) {
            if (width > 0 && width + words[i].size() + 1 > maxWidth) {
                int gaps = i - left - 1;
                int residue = maxWidth - width;
                int extra = gaps ? (residue + gaps - 1) / gaps : 0;
                int boundary = gaps ? gaps - (extra * gaps - residue) : -1;
                string line;
                for (int j = 0; j < i - left; ++j) {
                    if (j - 1 == boundary) --extra;
                    line += (j ? string(extra + 1, ' ') : "") + words[left + j];
                }
                line += string(maxWidth - line.size(), ' ');
                result.push_back(line);
                width = 0;
                left = i;
            }
            width += words[i].size() + (width ? 1 : 0);
        }
        string line;
        for (int i = 0; i < words.size() - left; ++i)
            line += (i ? " " : "") + words[left + i];
        line += string(maxWidth - line.size(), ' ');
        result.push_back(line);
        return result;
    }
};