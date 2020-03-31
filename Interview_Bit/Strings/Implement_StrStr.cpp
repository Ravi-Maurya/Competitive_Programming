void LPSArray(vector<int>& lps, const string& pat){
    int n = pat.size();
    int length = 0;
    lps[0]=0;
    int i =1;
    while(i<n){
        if(pat[i]==pat[length]){
            length++;
            lps[i]=length;
            i++;
        }
        else{
            if(length!=0)
                length = lps[length-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int Solution::strStr(const string A, const string B) {
    int m = B.size();
    int n = A.size();
    vector<int> lps(m);
    LPSArray(lps,B);
    int i=0,j=0;
    while(i<n){
        if(B[j]==A[i]){
            i++;
            j++;
        }
        if(j==m){
            return i-j;
        }
        else if(i<n && B[j]!=A[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return -1;
}
