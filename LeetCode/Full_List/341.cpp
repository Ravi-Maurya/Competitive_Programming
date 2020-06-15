/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> dq;
    NestedIterator(vector<NestedInteger> &nestedList) {
        build(nestedList);
    }
    
    void build(vector<NestedInteger> &nestedList){
        for(auto& x: nestedList){
            if(x.isInteger())
                dq.push(x.getInteger());
            else
                build(x.getList());
        }
        return;
    }
    
    int next() {
        int t = dq.front();dq.pop();
        return t;
    }
    
    bool hasNext() {
        return !dq.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */