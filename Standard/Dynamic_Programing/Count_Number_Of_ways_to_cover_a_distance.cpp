#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
int count_dist(int n){// for steps 1,2,3
    if(n<=1)//[1]
        return 1;
    if(n==2)// [1,1], [2]
        return 2;
    if(n==3)// [1,1,1], [1,2], [2,1], [3]
        return 4;
    int i_1 = 4, i_2 = 2, i_3 = 1;
    int res;
    for(int i=4; i<=n;i++){
        res = i_1 + i_2 + i_3;
        i_3 = i_2;
        i_2 = i_1;
        i_1 = res;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}