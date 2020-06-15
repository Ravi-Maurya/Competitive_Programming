class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int l=s.size();
        int left=l-2;
        int right=l-1;
        next_permutation(s.begin(),s.end());
        long long int y=stoll(s);
        if(y>INT_MAX || y<=n)
            return -1;
        else
            return y;
    }
};