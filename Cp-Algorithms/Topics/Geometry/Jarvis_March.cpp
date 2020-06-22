#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

struct Point{
    int x, y;
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

int crossProduct(Ponint a, Point b, Point c){//ab x ac
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return (y2*x1 - y1*x2);
}

int distance(Ponint a, Point b, Point c){// <0 if b is closer , >0 if c is closer and =0 if b and c are at same point
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    int d1 = y1*y1 + x1*x1;
    int d2 = y2*y2 + x2*x2;
    if(d1<d2)
        return -1;
    else if(d1==d2)
        return 0;
    return 1;
}

vector<Point> convex_hull(vector<Point>& points){
    if(points.size<=3)
        return points;
    Point start = points[0];//find left most point
    for(int i=1;i<points.size(); i++)
        if(points[i].x<start.x)
            start = points[i];
    Point curr = start;
    unordered_set<Point> res;
    visited.insert(start);
    vector<Point> colinear;
    while(true){
        Point next = points[0];
        for(int i=1; i<points.size(); i++){
            if(points[i]==curr)
                continue;
            int cross = crossProduct(curr,next,points[i]);
            if(cross>0){
                next = points[i];
                colinear.clear();
            }
            else if(cross == 0){
                if(distance(curr,next,points[i])<0){
                    colinear.push_back(next);
                    next = points[i];
                }
                else{
                    colinear.push_back(points[i]);
                }
            }
        }
        for(auto p: colinear)
            res.insert(p);
        if(next == start)
            break;
        res.insert(next);
        curr = next;
    }
    return vector<Point>(res.begin(),res.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}