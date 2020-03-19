vector<int> Solution::flip(string A) {
    int n = A.size(),i;
    vector <int> Vec(n,1);
    int cnt = 0;
    for(i=0;i<n;i++)
        if (A[i]=='1'){
            Vec[i] = -1;
            cnt++;
        }
    if (cnt==n){
        vector <int> res;
        return res;
    }
    vector <int> res(2);
    int start = 0;
    int curr_max = 0, global_max = INT_MIN;
    for(i=0;i<n;i++){
        curr_max += Vec[i];
        if (curr_max>global_max && curr_max>=0){
            global_max = curr_max;
            res[0] = start+1;
            res[1] = i+1;
        }
        else if (curr_max<0){
            curr_max = 0;
            start = i+1;
        }
    }
    return res;
}
