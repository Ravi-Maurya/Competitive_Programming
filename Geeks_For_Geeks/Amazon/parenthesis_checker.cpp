#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    unordered_set<char> opening;
    opening.insert('{');
    opening.insert('(');
    opening.insert('[');
    for(int test = 1; test <= t; test++){
        string exp;
        cin>>exp;
        if(opening.find(exp[0])==opening.end()){
            cout<<"not balanced"<<"\n";
            continue;
        }
        stack<char> s;
        bool isBalenced = true;
        for(int i=0; i<exp.size(); i++){
            if(i==0 || opening.find(exp[i])!=opening.end())
                s.push(exp[i]);
            else if(!s.empty() && ((exp[i]=='}' && s.top()=='{')||(exp[i]==')' && s.top()=='(')||(exp[i]==']' && s.top()=='['))){
                    s.pop();
            }
            else{
                isBalenced = false;
                break;
            }
        }
        if(!isBalenced)
            cout<<"not balanced"<<"\n";
        else{
            isBalenced = s.empty();
            if(!isBalenced)
                cout<<"not balanced"<<"\n";
            else
                cout<<"balanced"<<"\n";
        }
    }
    return 0;
}