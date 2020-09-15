class Solution {
public:   
    bool judgePoint24(vector<int>& nums) {
        vector<double> a(nums.begin(), nums.end());
        return solve(a);
    }
    
    bool solve(vector<double> a) {
        const double eps = 0.001;
        if(a.size() == 1) return abs(a[0] - 24) < eps;
        
        for (int i=0; i<a.size(); i++) {
            for (int j=i+1; j<a.size(); j++) {
                vector<double> b(a.size() -1);
                
                for (int k=0, index=0; k<a.size(); k++) {
                    if(k!=i && k!=j) {
                        b[index++] = a[k];
                    }
                }
                
                for (double d: compute(a[i], a[j])) {
                    b[b.size()-1] = d;
                    if(solve(b)) return true;
                }
            }
        }
        
        return false;
    }
    
    vector<double> compute(double x, double y) {
        return {x+y, x-y, y-x, x*y, x/y, y/x};
    }
};