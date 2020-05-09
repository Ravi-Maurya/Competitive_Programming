class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, posSum = 0, index = 0;
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
            sum += gas[i];
            posSum += gas[i];
            if (posSum < 0) {
                posSum = 0;
                index = i+1;
            }
        }
        return (sum<0) ? -1 : index;
    }
};