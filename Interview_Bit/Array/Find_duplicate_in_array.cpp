// Use Concept of Linked Lists as indexes and values are to be linked.
int Solution::repeatedNumber(const vector<int> &A) {
    int slow,fast;
    slow = A[0];
    fast = A[A[0]];
    while (slow!=fast){
        slow = A[slow];
        fast = A[A[fast]];
    }
    fast = 0;
    while(slow!=fast){
        slow = A[slow];
        fast = A[fast];
    }
    if (slow==0) return -1;
    return slow;
}
