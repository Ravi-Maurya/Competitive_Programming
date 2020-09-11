class Solution {
public:
    int maxAbsValExpr(vector<int>& v1, vector<int>& v2) {
        // open absolute
        int m1=INT_MIN;
        int m3=INT_MIN;
        int m5=INT_MIN;
        int m7=INT_MIN;
        int m2=INT_MAX;
        int m4=INT_MAX;
        int m6=INT_MAX;
        int m8=INT_MAX;

        for(int i=0;i<v1.size();i++){
            m1=max(m1,v1[i]+v2[i]+i);
            m2=min(m2,v1[i]+v2[i]+i);
            m3=max(m3,v1[i]-v2[i]+i);
            m4=min(m4,v1[i]-v2[i]+i);
            m5=max(m5,v1[i]+v2[i]-i);
            m6=min(m6,v1[i]+v2[i]-i);
            m7=max(m7,v1[i]-v2[i]-i);
            m8=min(m8,v1[i]-v2[i]-i);
        }
        
        int val1=m1-m2;
        int val2=m3-m4;
        int val3=m5-m6;
        int val4=m7-m8;
        return max(max(val1,val2),max(val3,val4));
    }
};