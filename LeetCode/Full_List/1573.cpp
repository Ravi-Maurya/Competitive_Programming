const int mod = 1e9 + 7;
class Solution {
public:
    int mod_mul(int x, int y){
        int res = 0;
        for(int i=0; i<x; i++){
            res = res%mod + y%mod;
            res %= mod;
        }
        return res%mod;
    }
    int numWays(string s) {
        int count_one = 0, n = s.size();
        for(int i=0; i<n; i++)
            if(s[i]=='1')
                count_one++;
        if(count_one==0){
            long long int res = (((long long)(n-1))*((long long)(n-2)))/2;
            return res%mod;
        }
        if(count_one%3 != 0)
            return 0;
        int x = count_one/3;
        vector<pair<int,int>> res(3,{-1,-1});
        int j = 0;
        res[j].first = 0;
        int c = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                x--;
                if(res[j].second == -1)
                    res[j].second = i;
            }
            if(x==0){
                c++;
                if(c==3)
                    break;
                x = count_one/3;
                j++;
                res[j].first = i+1;
            }
        }
        // for(int i=0; i<3; i++){
        //     cout<<res[i].first << " " << res[i].second << "\n";
        // }
        int y = mod_mul(res[1].second-res[1].first + 1,res[2].second-res[2].first + 1);
        return y;
    }
};