class Solution {
public:
    bool isHappy(int n) {
        int ans=0;
        unordered_set<int> s;
        while(1)
        {
            int sum=0;
            while(n)
            {
                sum+=pow(n%10,2);
                n/=10;
            }
            if(s.find(sum)!=s.end())break;
            s.insert(sum);
            if(sum==1)return true;
            n=sum;
        }
        return false;
    }
};