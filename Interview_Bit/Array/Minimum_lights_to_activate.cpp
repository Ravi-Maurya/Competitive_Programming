int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0;
    int count = 0;
    while(i<n){
        int light_index = -1;
        int left = max(0, i - B + 1);
        int right = min(n-1 , i + B - 1);
        while(right>=left){
            if(A[right] == 1){
                light_index = right;
                break;
            }
            right--;
        }
        if(light_index == -1){
            return -1;
        }
        count++;
        i = light_index + B ;
    }
    return count;
}
