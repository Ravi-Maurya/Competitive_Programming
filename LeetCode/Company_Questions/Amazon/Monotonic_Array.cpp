#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for(int i=0; i<A.size()-1; i++){
            if(A[i]>A[i+1])
                inc = false;
            if(A[i]<A[i+1])
                dec = false;
            if(!inc && !dec)
                return false;
        }
        return inc||dec;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}