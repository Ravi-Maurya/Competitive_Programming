# define mod 1000000007
int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> maxheap;
    int n = B.size(),i;
    long long int res = 0;
    for(i=0;i<n;i++)
        maxheap.push(B[i]);
    for(i=0;i<A;i++){
        int top = maxheap.top();
        if(top==0)
            break;
        res += top;
        res %= mod;
        maxheap.pop();
        maxheap.push(top/2);
    }
    return res%mod;
}
