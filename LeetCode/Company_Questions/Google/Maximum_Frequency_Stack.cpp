class FreqStack {
public:
    stack<int> latest[10001];
    map<int, int> frequency;
    map<int, int, greater <int> > num_items;

    FreqStack() {
    }
    
    void push(int x) {
        frequency[x]++;
        latest[frequency[x]].push(x);
        num_items[frequency[x]]++;
    }
    
    int pop() {
        int max_freq = num_items.begin()->first;
        int current = latest[max_freq].top();
        latest[max_freq].pop();
        num_items[max_freq]--;
        if(num_items[max_freq] == 0) {
            num_items.erase(max_freq);
        }
        frequency[current]--;
        return current;
    }
};