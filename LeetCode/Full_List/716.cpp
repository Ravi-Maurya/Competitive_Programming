class MaxStack {
    stack<int>s1;
    stack<int>s2;
public:
   void push(int x) {
       s1.push(x);
       if (s2.empty() || s2.top()<=x) s2.push(x);
    }
    int pop() {
        int x = s1.top();
        s1.pop();
        if (x==peekMax()) s2.pop();
        return x;
    }
    int top() { 
        return s1.top();
    }
    int peekMax() { 
        return s2.top(); 
    }
    int popMax() { 
        int x = peekMax();
        stack<int> tmp;
        while(top()!=x) tmp.push(pop());
        pop();
        while(!tmp.empty()) {
            push(tmp.top()); 
            tmp.pop();
        }
 
        return x;
    }
};