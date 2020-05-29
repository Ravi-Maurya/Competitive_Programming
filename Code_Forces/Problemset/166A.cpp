#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool notdistinct(int x){
    unordered_set<int> visited;
    while(x>0){
        int t = x%10;
        x /= 10;
        if(visited.count(t))
            return true;
        visited.insert(t);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    do{
        n++;
    }while(notdistinct(n));
    cout<<n<<"\n";
    return 0;
}