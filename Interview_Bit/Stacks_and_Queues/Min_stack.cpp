stack<int> min_stack;
int minElem = INT_MAX;
MinStack::MinStack() {
    while(!min_stack.empty())
        min_stack.pop();
    minElem = INT_MAX;
}
void MinStack::push(int x) {
    if(min_stack.empty()){
        min_stack.push(x);
        minElem = x;
    }
    else{
        if(x>=minElem)
            min_stack.push(x);
        else{
            min_stack.push(2*x - minElem);
            minElem = x;
        }
    }
}

void MinStack::pop() {
    if(!min_stack.empty()){
        int y = min_stack.top();
        min_stack.pop();
        if(y<minElem){
            minElem = 2*minElem - y;
        }
    }
}

int MinStack::top() {
    if(min_stack.empty())
        return -1;
    int t = min_stack.top();
    return (t<minElem) ? minElem : t;
}

int MinStack::getMin() {
    if(min_stack.empty())
        return -1;
    return minElem;
}

