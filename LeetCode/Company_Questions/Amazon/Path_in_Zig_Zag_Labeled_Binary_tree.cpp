class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log2(label) + 1;  
        vector<int> path(level);
        while (label) {
            path[level - 1] = label;
            label = pow(2, level) - 1 - label + pow(2, level - 1);
            label >>= 1;
            level--;
        }
        return path;
    }
};