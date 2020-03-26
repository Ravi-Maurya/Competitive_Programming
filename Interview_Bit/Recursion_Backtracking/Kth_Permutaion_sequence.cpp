void nextPermutation(vector<int> &res) {
    int n = res.size(),i;
    int invert = n-2;
    while (invert>=0 && res[invert]>=res[invert+1]) invert--;
    if (invert==-1){
        reverse(res.begin(),res.end());
        return;
    }
    for(i = n-1; i>=invert+1; i--){
        if (res[i]>res[invert]){
            swap(res[i],res[invert]);
            break;
        }
    }
    reverse(res.begin()+(invert+1),res.end());
    return;
}

string Solution::getPermutation(int B, int A) {
    vector<int> res;
    for(int i=1;i<=B;i++)
        res.push_back(i);
    A -= 1;
    while(A>0){
        nextPermutation(res);
        A-=1;
    }
    string s = "";
    for(auto x: res){
        s += to_string(x);
    }
    return s;
}
