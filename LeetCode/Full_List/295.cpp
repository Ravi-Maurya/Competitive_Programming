class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {}
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

// Best Sol
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    
    void addNum(int num) {
        if(left.size()==0){
            left.push(num);
            return;
        }
        
        if(num<=left.top())
            left.push(num);
        else
            right.push(num);
        
        if((left.size()-right.size()) == 2){
            right.push(left.top());
            left.pop();
        }
        if((right.size()-left.size()) == 2){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        double ans;
        if(left.size()>right.size())
            ans=(double) left.top();
        else if(right.size()>left.size())
            ans=(double) right.top();
        else
            ans=(double) (left.top()+right.top())/2;
        
        return ans;
    }
};