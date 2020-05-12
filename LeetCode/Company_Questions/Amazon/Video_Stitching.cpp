class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int i = 0, max_possible = 0, count = 0;
        while(max_possible<T){
            int curr_max = 0;
            while(i<clips.size() && clips[i][0]<=max_possible)
                curr_max = max(curr_max,clips[i++][1]);
            if(curr_max<=max_possible)
                return -1;
            max_possible = curr_max;
            count++;
        }
        return count;
    }
};