class MyCalendarThree {
public:
    map<int,int> check;
    MyCalendarThree() {
        check.clear();
    }
    
    int book(int start, int end) {
        check[start]++;
        check[end]--;
        int active = 0, res = 0;
        for(auto& [key,values]: check){
            active += values;
            if(active>res)
                res = active;
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
struct Tree{
    int start,end,booked,res;
    Tree* left;
    Tree* right;
    Tree(int s, int e){
        start = s;
        end = e;
        booked = res = 0;
        left = NULL;
        right = NULL;
    }
    void add(int s, int e, int val){
        if(e<start || s>end)
            return;
        if(s<=start && e>=end){
            booked += val;
            res += val;
        }
        else{
            int mid = start + (end-start)/2;
            if(!left)
                left = new Tree(start,mid);
            if(!right)
                right = new Tree(mid+1,end);
            left->add(s,e,val);
            right->add(s,e,val);
            res = max(left->res,right->res) + booked;
        }
    }
};

class MyCalendarThree {
public:
    Tree* root;
    MyCalendarThree() {
        root = new Tree(0,1000000000);
    }
    
    int book(int start, int end) {
        root->add(start,end-1,1);
        return root->res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */