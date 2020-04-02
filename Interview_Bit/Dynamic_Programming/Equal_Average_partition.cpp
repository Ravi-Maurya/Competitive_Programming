vector<vector<vector<bool>>> dp;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int index, int sum, int sz) {
    if (sz == 0) return (sum == 0);
    if (index >= total_size) return false;

    if (dp[index][sum][sz] == false) return false;

    if (sum >= original[index]) {
        res.push_back(original[index]);
        if (possible(index + 1, sum - original[index], sz - 1)) return true;
        res.pop_back();
    }

    if (possible(index + 1, sum, sz)) return true;

    return dp[index][sum][sz] = false;
}

vector<vector<int>> Solution::avgset(vector<int> &Vec) {
    sort(Vec.begin(), Vec.end());
    original.clear();
    original = Vec;
    dp.clear();
    res.clear();

    int total_sum = 0;
    total_size = Vec.size();

    for (int i = 0; i < total_size; ++i)
        total_sum += Vec[i];
    if(total_sum&1)
        return {};
    dp.resize(original.size(), vector<vector<bool>>(total_sum + 1, vector<bool>(total_size, true)));
    for (int i = 1; i < total_size; i++) {
        if ((total_sum * i) % total_size != 0) continue;
        int Sum_of_Set1 = (total_sum * i) / total_size;
        if (possible(0, Sum_of_Set1, i)) {
            int ptr1 = 0, ptr2 = 0;
            vector<int> res1 = res;
            vector<int> res2;
            while (ptr1 < Vec.size() || ptr2 < res.size()) {
                if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                res2.push_back(Vec[ptr1]);
                ptr1++;
            }

            vector<vector<int>> ans;
            ans.push_back(res1);
            ans.push_back(res2);
            return ans;
        }
    }
    vector<vector<int>> ans;
    return ans;
}