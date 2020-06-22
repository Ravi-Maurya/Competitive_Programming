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
    double x,y;
};

bool compare(Point a, Point b){
    if(a.x == b.x)
        return a.y<b.y;
    return a.x<b.x;
}

bool crossProduct(Ponint a, Point b, Point c){//ab x ac
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return (y2*x1 - y1*x2)<=0;
}

bool anticrossProduct(Ponint a, Point b, Point c){//ab x ac
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return (y2*x1 - y1*x2)>=0;
}

vector<Point> convex_hull(vector<Point>& arr){//O(nlogn)
    if(arr.size()<=3)
        return arr;
    sort(arr.begin(),arr.end(),&compare);
    Point p1 = arr[0], p2 = arr.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i=1; i<arr.size();i++){
        if(i==arr.size()-1 || crossProduct(p1,arr[i],p2)){
            while(up.size()>=2 && !crossProduct(up[up.size()-2],up[up.size()-1],arr[i]))
                up.pop_back();
            up.push_back(arr[i]);
        }
        if(i==arr.size()-1 || anticrossProduct(p1,arr[i],p2)){
            while(down.size()>=2 && anticrossProduct(down[down.size()-2],down[down.size()-1],arr[i]))
                down.pop_back();
            down.push_back(arr[i]);
        }
    }
    for(int i=down.size()-2; i>0; i--)
        up.push_back(down[i]);
    return up;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}