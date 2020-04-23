class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mapp(26,0);
        int res = tasks.size();
        for(auto ch: tasks)
            mapp[ch-'A']++;
        sort(mapp.begin(),mapp.end());
        int mx = mapp[25]-1, idle = mx*n;
        for(int i=24; i>=0 ;i--)
            idle -= min(mx,mapp[i]);
        if(idle>0)
            res += idle;
        return res;
    }
};