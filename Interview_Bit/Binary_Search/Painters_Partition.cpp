int mod = 10000003;
int check(long long int A,long long int B, vector<int> &C,long long int Time) {
    long long int curTime = 0;
    int curPainter = 1;
    for(int i=0;i<C.size();i++) {
        if(curTime + C[i]*B > Time) {
            curPainter++;
            if(curPainter > A) {
                return 0;
            }
            curTime = 0;
            i--;
        } else {
            curTime += C[i]*B;
        }
    }
    return 1;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int low = 0;
    long long int high = 0;
    for(int i=0; i<C.size(); i++) high += ((long long)B)*C[i];
    int ans;
    while(low<=high) {
        long long int mid = (low+high)/2;
        if(check(A,B,C,mid)) {
            high = mid-1;
            ans = mid%mod;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}