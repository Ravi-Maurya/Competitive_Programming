class Solution {
    vector<vector<int>> rectangles;
    vector<int> area;
public:
    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        int cum_area = 0;
        for(auto& r: rectangles){
            cum_area += (r[2]-r[0]+1)*(r[3]-r[1]+1);
            area.push_back(cum_area);
        }
    }
    
    vector<int> pick() {
        int rand_area = rand()%area.back();
        int idx = upper_bound(area.begin(),area.end(),rand_area) - area.begin();
        auto r = rectangles[idx];
        int x = rand() % (r[2]-r[0]+1)  + r[0];
        int y = rand() % (r[3]-r[1]+1)  + r[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */