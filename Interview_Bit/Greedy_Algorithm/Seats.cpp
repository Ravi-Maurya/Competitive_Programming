#define MOD 10000003
int Solution::seats(string A) {
    vector<int> x;
    for(int i=0;i<A.size();i++)
        if(A[i]=='x')
            x.push_back(i);
    int n = x.size(),position=1;
    int mid = n/2;
    long long int res = 0;
    // Position = # of right side people to be positioned
    for(int i=mid-1;i>=0;i--){
        res = (res+ (x[mid]-x[i]) - position)%MOD;
        position++;
    }
    position = 1;
    for(int i=mid+1;i<n;i++){
        res = (res + (x[i]-x[mid]) - position)%MOD;
        position++;
    }
    return res%MOD;
}
