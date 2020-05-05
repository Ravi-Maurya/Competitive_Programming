class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<2)
            return n;
        map<pair<int,int>,int> slopes;
        int res = 0, currmax, overlap, verticals;
        for(int i=0; i<n; i++){
            currmax = overlap = verticals = 0;
            for(int j=i+1; j<n; j++){
                if((points[i][0] == points[j][0]) && (points[i][1] == points[j][1]))
                    overlap++;
                else if(points[i][0]==points[j][0])
                    verticals++;
                else{
                    int ydiff = points[j][1] - points[i][1];
                    int xdiff = points[j][0] - points[i][0];
                    int g = __gcd(xdiff,ydiff);
                    ydiff /= g;
                    xdiff /= g;
                    slopes[{ydiff,xdiff}]++;
                    currmax = max(currmax, slopes[{ydiff,xdiff}]);
                }
                currmax = max(currmax, verticals);
            }
            res = max(res, currmax + overlap + 1);
            slopes.clear();
        }
        return res;
    }
};