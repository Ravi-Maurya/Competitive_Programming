class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty())
            return 0;
        vector<int> frequency(26,0);
        for(auto ch: tasks)
            frequency[ch-'A']++;
        sort(frequency.begin(),frequency.end(),greater<int>());
        int curr = frequency[0];
        int count = 1;
        while(count<26 && frequency[count]==curr)
            count++;
        int res = max(n+1,count)*(curr-1) + count;
        res = max(res,(int)tasks.size());
        return res;
    }
};