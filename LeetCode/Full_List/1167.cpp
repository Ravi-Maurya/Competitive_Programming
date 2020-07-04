class Solution {
public:
    int connectSticks(vector<int>& sticks) {
      priority_queue <int, vector<int>, greater<int> > pq (sticks.begin(), sticks.end()); 
      
      int cost = 0;
      while (pq.size() > 1) {
        auto min = pq.top(); 
        pq.pop();
        
        auto second_min = pq.top();
        pq.pop();
        
        auto added = min + second_min;
        cost += added;
        pq.push(added);
      }
      
      return cost;
    }
};