int Solution::singleNumber(const vector<int> &A) {
    int res = 0;
    for(int i =0 ;i<32;i++){
        int sum = 0;
        int x = (1<<i);
        for(int a:A){
            if (a&x)
                sum++;
        }
        if (sum%3)
            res |= x;
    }
    return res;
}
