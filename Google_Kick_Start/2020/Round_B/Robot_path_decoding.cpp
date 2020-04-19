// Test case 2 - WAs

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

const int mod = 1e9;

void add_self(long long int& a, long long int b){
    a += b;
    if(a<=0)
        a += mod;
    else if(a>mod)
        a -= mod;
}

void mul_self(long long int& a, int b){
    a *= b;
    if(a>mod)
        a-=mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        string s;
        cin>>s;
        long long int curr_row = 1, curr_col = 1;
        long long int times = 1;
        stack<long long int> times_stack;
        times_stack.push(times);
        auto it = s.cbegin();
        while (it != s.cend()){
            times = times_stack.top();
            if(*it == 'N')
                add_self(curr_col, -1*times);
            else if(*it == 'S')
                add_self(curr_col, 1*times);
            else if(*it == 'E')
                add_self(curr_row, 1*times);
            else if(*it == 'W')
                add_self(curr_row, -1*times);
            else if('2'<= *it && *it <='9'){
                mul_self(times,(*it-'0'));
                times_stack.push(times);
            }
            else if(*it==')')
                times_stack.pop();
            it++;
        }
        cout<<"Case #"<<test<<": "<<curr_row<<" "<<curr_col<<"\n";
        
    }
    return 0;
}