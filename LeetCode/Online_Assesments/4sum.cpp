#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<vector<int> > fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size(),i,j,k,l;
    set<vector<int>> s;
    vector<vector<int>> res;
    if (n<4)
        return res;
    for(i=0;i<n-3;i++){
        for(j=i+1;j<n-2;j++){
        k = j+1;
        l = n-1;
        while(k<l){
            if(A[i]+A[j]+A[k]+A[l]- B == 0){
                s.insert({A[i],A[j],A[k],A[l]});
                k++;
                l--;
            }
            else if(A[i]+A[j]+A[k]+A[l]>B)
                l--;
            else
                k++;
        }
        }
    }
    for(auto x:s)
        res.push_back(x);
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}