int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    for(int i=0;i<n;i++){
        int amount = A[i];
        if(amount<B[i])
            continue;
        amount -= B[i];
        int j = (i+1)%n;
        while(j!=i){
            amount += A[j];
            if(amount<B[j])
                break;
            amount -= B[j];
            j = (j+1)%n;
        }
        if(j==i)
            return i;
    }
    return -1;
}
