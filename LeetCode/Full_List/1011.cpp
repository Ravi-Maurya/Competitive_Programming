class Solution {
public:
    
    bool check(vector<int>& weights, int D, int x){
        int n = weights.size();
        int curr = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            curr += weights[i];
            if(curr<=x)
                continue;
            curr = weights[i];
            ++count;
            if(count>D || curr>x)
                return false;
        }
        if(count+1>D || curr>x)
            return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int low = weights[0];
        int high = weights[0];
        for(int i=1; i<n; i++){
            if(weights[i]>low)
                low = weights[i];
            high += weights[i];
        }
        while(low<high){
            int mid = low + (high-low)/2;
            // cout<<low<<" "<<high<<" (low,high)\t" << mid << "\n";
            if(check(weights,D,mid))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
};