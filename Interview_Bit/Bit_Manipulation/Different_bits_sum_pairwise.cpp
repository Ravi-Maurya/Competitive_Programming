#define MOD 1000000007
int Solution::cntBits(vector<int> &A) {
    int bits = 31,i,res=0;
    for(i=0;i<bits;i++){
        long long int zeros = 0, ones = 0;
        int mask = 1<<i;
        for(int x:A){
            if (x&mask)
                ones++;
            else
                zeros++;
        }
        res += (ones*zeros)%MOD;
        res %= MOD;
    }
    return (res*2)%MOD;
}
