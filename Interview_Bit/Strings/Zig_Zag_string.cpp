string Solution::convert(string A, int B) {
    int n = A.size();
    vector<int> tmp(n);
    bool flag = 0;
    int c = 1;
    vector<string> res(B);
    for(int i=0;i<n;i++){
        tmp[i]=c;
        res[tmp[i]-1]+=A[i];
        if(c<B && flag==0)
            c++;
        if(c>1 && flag==1)
            c--;
        if(c==B||c==1){
            if(flag==0)
                flag =1;
            else
                flag = 0;
        }
    }
    string ans ="";
    for(int i=0;i<B;i++)
        ans += res[i];
    return ans;
}
