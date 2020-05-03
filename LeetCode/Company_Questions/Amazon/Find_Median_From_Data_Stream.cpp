class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        while(!max_heap.empty())
            max_heap.pop();
        while(!min_heap.empty())
            min_heap.pop();
    }
    void addNum(int num) {
        if(!max_heap.size()){
            max_heap.push(num);
            return;
        }
        if(max_heap.size()>min_heap.size()){
            if(num>=max_heap.top()){
                min_heap.push(num);
                return;
            }
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(num);
            return;
        }
        else{
            if(min_heap.top()>=num){
                max_heap.push(num);
                return;
            }
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(num);
            return;
        }
        
    }
    
    double findMedian() {
        if(max_heap.size()==min_heap.size()){
            return (max_heap.top() + min_heap.top())/2.0;
        }
        else{
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */