vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    int left = 0;
    int window_size = 0;
    int count = 0,left_index = 0;
    for(int right=0;right<n;right++){
        if (A[right]==0)
            count++;
        while (count>B){
            if (A[left]==0)
                count--;
            left++;
        }
        if (right-left+1>window_size){
            window_size = right-left+1;
            left_index = left;
        }
    }
    vector <int> res;
    for(int i=left_index; i<=left_index+window_size-1;i++)
        res.emplace_back(i);
    return res;
}
