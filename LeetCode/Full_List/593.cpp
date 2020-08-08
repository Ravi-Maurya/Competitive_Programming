class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2){
        return ((p2[1]-p1[1])*(p2[1]-p1[1]))+((p2[0]-p1[0])*(p2[0]-p1[0]));
    }
    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        return (distance(p1,p2)>0) && (distance(p1,p2)==distance(p2,p3))&& (distance(p2,p3)==distance(p3,p4))&& (distance(p3,p4)==distance(p4,p1)) && (distance(p1,p3)==distance(p2,p4));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return check(p1,p2,p3,p4)||check(p1,p3,p2,p4)||check(p1,p2,p4,p3);
    }
};