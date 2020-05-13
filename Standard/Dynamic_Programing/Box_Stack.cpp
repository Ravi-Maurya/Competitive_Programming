#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct Box{
    int h,w,d;
};

bool compare(Box b1, Box b2){
    return b2.d*b2.w >= b1.d*b1.w;
}

int max_stack(vector<Box>& arr){
    int n = arr.size();
    vector<Box> rotated(3*n);
    int idx = 0;
    for(int i=0; i<n; i++){
        rotated[idx].h = arr[i].h;
        rotated[idx].d = max(arr[i].d, arr[i].w);
        rotated[idx].w = min(arr[i].d, arr[i].w);
        idx++;
        rotated[idx].h = arr[i].w;
        rotated[idx].d = max(arr[i].h, arr[i].d);
        rotated[idx].w = min(arr[i].h, arr[i].d);
        idx++;
        rotated[idx].h = arr[i].d;
        rotated[idx].d = max(arr[i].h, arr[i].w);
        rotated[idx].w = min(arr[i].h, arr[i].w);
        idx++;
    }
    sort(rotated.begin(), rotated.end(), compare);
    vector<int> lis(3*n);
    for(int i=0; i<3*n; i++){
        lis[i] = rotated[i].h;
    }
    for(int i=1; i<3*n; i++)
        for(int j=0;j<i;j++)
            if(rotated[i].w < rotated[j].w && rotated[i].d<rotated[j].d && lis[i]<lis[j]+rotated[i].h)
                lis[i] = lis[j] + rotated[i].h;
    return *max_element(lis.begin(), lis.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}