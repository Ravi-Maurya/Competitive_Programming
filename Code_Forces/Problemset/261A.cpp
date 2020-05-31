#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int x1, y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    pair<int,int> p1,p2,p3,p4;
    if((x1<x2) || (x1==x2 && y1<y2)){
        p1 = {x1,y1};
        p2 = {x2,y2};
    }
    else{
        p1 = {x2,y2};
        p2 = {x1,y1};
    }
    if(p1.first == p2.first){
        int d = abs(p1.second - p2.second);
        if((p1.first + d)<=100){
            p3 = {p1.first + d,p1.second};
            p4 = {p2.first + d,p2.second};
        }
        else{
            p3 = {p1.first - d,p1.second};
            p4 = {p2.first - d,p2.second};
        }
    }
    else if(p1.second == p2.second){
        int d = abs(p1.first - p2.first);
        if((p1.second + d)<=100){
            p3 = {p1.first,p1.second+d};
            p4 = {p2.first,p2.second+d};
        }
        else{
            p3 = {p1.first,p1.second-d};
            p4 = {p2.first,p2.second-d};
        }
    }
    else{
        if(abs(p1.first - p2.first)!=abs(p1.second - p2.second)){
            cout<<-1<<"\n";
            return 0;
        }
        p3 = {p1.first,p2.second};
        p4 = {p2.first,p1.second};
    }
    cout<<p3.first<<" "<<p3.second<<" "<<p4.first<<" "<<p4.second<<"\n";
    return 0;
}