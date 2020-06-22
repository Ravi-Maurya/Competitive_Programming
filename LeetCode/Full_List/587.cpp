class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    bool cw(vector<int>& a, vector<int>& b, vector<int>& c){
        int y1 = a[1] - b[1];
        int y2 = a[1] - c[1];
        int x1 = a[0] - b[0];
        int x2 = a[0] - c[0];
        return (y2*x1 - y1*x2)<=0;
    }
    
    bool ccw(vector<int>& a, vector<int>& b, vector<int>& c){
        int y1 = a[1] - b[1];
        int y2 = a[1] - c[1];
        int x1 = a[0] - b[0];
        int x2 = a[0] - c[0];
        return (y2*x1 - y1*x2)>=0;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& arr) {
        if(arr.size()<=3)
            return arr;
        sort(arr.begin(),arr.end(),compare);
        auto p1 = arr[0], p2 = arr.back();
        vector<vector<int>> up,down;
        up.push_back(p1);
        down.push_back(p1);
        for(int i=1; i<arr.size();i++){
            if(i==arr.size()-1 || cw(p1,arr[i],p2)){
                while(up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],arr[i]))
                    up.pop_back();
                up.push_back(arr[i]);
            }
            if(i==arr.size()-1 || ccw(p1,arr[i],p2)){
                while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],arr[i]))
                    down.pop_back();
                down.push_back(arr[i]);
            }
        }
        for(int i=down.size()-2; i>0; i--)
            up.push_back(down[i]);
        return up;
    }
};