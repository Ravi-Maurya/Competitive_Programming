#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class SortStack{
    public:
    void sortingInsert(stack<int>& s, int tmp){
        if(s.empty() || x>s.top())
            s.push(tmp), return;
        int tmp2 = s.top(); s.pop();
        sortingInsert(s,tmp);
        s.push(tmp2);
    }
    void sorting(stack<int>& s){
        if(!s.empty()){
            int tmp = s.top();
            s.pop();
            sorting(s);
            sortingInsert(s,tmp);
        }
    }
}

class MinStack{
    public:
    stack<int> s;
    int min_element;
    int n;
    MinStack(){
        while(!this->s.empty())
            this->s.pop();
        this->min_element = -1;
        this->n = 0;
    }
    int get_min(){
        if(this->n ==0)
            return -1;
        return this->min_element;
    }
    void push(int x){
        if(this->n == 0){
            this->s.push(x);
            this->min_element = x;
        }
        else{
            if(x<= this->get_min()){
                this->s.push(2*x - this->get_min());
                this->min_element = x;
            }
            else
                this->s.push(x);
        }
        this->n++;
        return;
    }

    void pop(){
        if(this->n == 0)
            return;
        int tmp = this->s.top();
        this->s.pop();
        int curr_min = this->get_min();
        if(tmp <= curr_min)
            this->min_element = 2*curr_min - tmp;
        this->n--;
        return;
    }

    int top(){
        if(this->n == 0)
            return -1;
        int tmp = this->s.top();
        int curr_min = this->get_min();
        if(tmp<=curr_min)
            return curr_min;
        return tmp;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}