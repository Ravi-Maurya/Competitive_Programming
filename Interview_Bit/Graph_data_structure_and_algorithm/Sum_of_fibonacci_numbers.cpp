int Solution::fibsum(int A) {
    vector<int> fib;
    int f = 1,s=1;
    fib.push_back(f);
    fib.push_back(s);
    while(1){
        int nxt = f+s;
        if(nxt>A)
            break;
        fib.push_back(nxt);
        f = s;
        s = nxt;
    }
    int count = 0, j = fib.size()-1;
    while(A>0){
        count += A/fib[j];
        A %= fib[j];
        j--;
    }
    return count;
}
