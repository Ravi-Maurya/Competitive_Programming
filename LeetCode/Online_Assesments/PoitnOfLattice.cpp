#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

string solve(int ax, int ay, int bx, int by){
    int dx = bx-ax, dy = by-ay;
    int rx = dy, ry = -dx;
    int gcd = __gcd(rx,ry);
    rx /= gcd;
    ry /= gcd;
    int resx = bx+rx, resy = by+ry;
    return to_string(resx)+","+to_string(resy);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}