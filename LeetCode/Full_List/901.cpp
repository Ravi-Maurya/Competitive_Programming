class StockSpanner {
public:
    stack<int> prices,wt;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int w = 1;
        while(!prices.empty() && prices.top()<=price){
            prices.pop();
            w += wt.top();wt.pop();
        }
        prices.push(price);
        wt.push(w);
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */