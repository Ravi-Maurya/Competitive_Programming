int Solution::singleNumber(const vector<int> &A) {
    int Xor = 0;
    for(int x:A){
        Xor ^= x;
    }
    return Xor;
}
