int Solution::majorityElement(const vector<int> &A) {
    vector<int> B(A.size());
    for(int i=0;i<A.size();i++)
        B[i] = A[i];
    sort(B.begin(),B.end());
    int x = A.size()/2;
    return B[x];
}
// If we remove each element corresponding to which they are not equal we will be left with the majority element
int Solution::majorityElement(const vector<int> &A) {
    int elem=0, count=1;
    for(int i=1; i<A.size(); ++i)
    {
        if(A[i]==A[elem]) ++count;
        else --count;
        if(count==0) elem=i, count=1;
    }
    return A[elem];
}
