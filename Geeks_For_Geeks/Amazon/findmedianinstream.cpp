#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int curr_median = -1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0){
            maxheap.push(x);
            cout<<x<<"\n";
        }
        else if(i==1){
            if(x>=maxheap.top())
                minheap.push(x);
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(x);
            }
            curr_median = (minheap.top() + maxheap.top())/2;
            cout<<curr_median<<"\n";
        }
        else{
            int diff = maxheap.size() - minheap.size();
            if(diff==0){
                if(x<=minheap.top())
                    maxheap.push(x);
                else{
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(x);
                }
                cout<<maxheap.top()<<"\n";
            }
            else{
                if(x>=maxheap.top())
                    minheap.push(x);
                else{
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(x);
                }
                curr_median = (minheap.top() + maxheap.top())/2;
                cout<<curr_median<<"\n";
            }
        }
    }
    return 0;
}