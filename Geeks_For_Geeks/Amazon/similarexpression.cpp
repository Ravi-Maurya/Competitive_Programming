#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool sign(string s, int i){
    if(i==0)
        return true;
    if(s[i-1]=='-')
        return false;
    return true;
}

void evaluate(string s, vector<int>& v, bool add){
    stack<bool> stck;
    stck.push(true);
    int i = 0;
    while(s[i]!='\0'){
        if(s[i] == '+' || s[i]=='-'){
            i++;
            continue;
        }
        if(s[i]=='('){
            if(sign(s,i))
                stck.push(stck.top());
            else
                stck.push(!stck.top());
        }
        else if(s[i]==')')
            stck.pop();
        else{
            if(stck.top())
                v[s[i]-'a'] += (sign(s,i) ? add ? 1: -1 : add? -1: 1);
            else
                v[s[i]-'a'] += (sign(s,i) ? add ? -1: 1 : add? 1: -1);
        }
        i++;
    }
}

bool check(string s1, string s2){
    vector<int> v(26,0);
    evaluate(s1,v,true);
    evaluate(s2,v,false);
    for(int i=0; i<26; i++)
        if(v[i]!=0)
            return false;
    return true;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        string s1,s2;
        cin>>s1>>s2;
        if(check(s1,s2))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}