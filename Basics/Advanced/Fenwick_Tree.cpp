#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class BIT{
    private:
    vector<int> bit;
    int n;
    public:
    BIT(vector<int>& arr){
        n = arr.size()+1;
        bit.clear();
        bit.resize(n,0);
        for(int i=0; i<n-1; i++)
            update(i,arr[i]);
    }

    void update(int idx, int val){
        idx += 1;
        while(idx<=n){
            bit[idx] += val;
            idx += idx&(-idx);
        }
        return;
    }
    int query(int idx){// gives [0,i] for [l,r] = query(r)-query(l-1);
        int sum = 0;
        idx += 1;
        while(idx>0){
            sum += bit[idx];
            idx -= idx&(-idx);
        }
        return sum;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}