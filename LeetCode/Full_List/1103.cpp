class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int curr = 1;
        int idx = 0;
        while(candies>0){
            if(candies-curr<0)
                res[idx] += candies;
            else
                res[idx] += curr;
            idx = (idx+1)%num_people;
            candies -= curr;
            curr++;
        }
        return res;
    }
};