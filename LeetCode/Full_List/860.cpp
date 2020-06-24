class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> change;
        change[5] = 0;change[10] = 0;change[20] = 0;
        for(auto x: bills){
            int diff = x-5;
            change[x]++;
            if(diff!=0){
                if(diff==5){
                    if(change[5]!=0)
                        change[5]--;
                    else
                        return false;
                }
                else{
                    if(change[10]>0 && change[5]>0){
                        change[10]--;
                        change[5]--;
                    }
                    else if(change[5]>=3){
                        change[5]-=3;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};