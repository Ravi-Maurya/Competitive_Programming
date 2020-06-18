class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for (int a : barcodes) {
            mp[a]++;
        }
        set<pair<int, int>> count;
        for (auto d : mp) {
            count.insert({d.second, d.first});
        }
        int pos=0;
        for (auto d = count.rbegin(); d != count.rend(); d++) {
            for (auto cnt = 0; cnt < d->first; ++cnt, pos += 2) {
                if (pos >= barcodes.size()) {
                    pos = 1;
                }
                barcodes[pos] = d->second;
            }
        }
        return barcodes;
    }
};