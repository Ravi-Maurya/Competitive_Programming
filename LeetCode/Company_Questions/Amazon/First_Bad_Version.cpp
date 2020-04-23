#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(isBadVersion(mid))
                r = mid;
            else l = mid+1;
        }
        return l;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}