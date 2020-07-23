class MovingAverage {
public:
    /** Initialize your data structure here. */
    deque<int> dq;
    long long int sum;
    int n;
    int k;
    MovingAverage(int size) {
        n = size;
        sum = 0;
        k = 0;
    }
    
    double next(int val) {
        ++k;
        dq.push_back(val);
        int t = 0;
        if(k>n){
            t = dq.front();
            dq.pop_front();
        }
        sum = sum-t+val;
        return (sum*1.0)/min(n,k);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */