#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool prime(int x) {
    if(x<=1)
        return false;
    if(x<=3)
        return true;
    if(x%3==0 || x%2==0)
        return false;
    for(int i=5; i*i<=x; i+=6){
        if((x%i) == 0 || x%(i+2)==0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    if(prime(n)){
        cout<<1<<"\n"<<n<<"\n";
        return 0;
    }
    for(int i = n-1; i>n-301; i--){
        if(prime(i)){
            for(int j=1;j<=300;j++){
                for(int k=1;k<=300;k++){
                    if(((j+k) == (n-i)) && prime(j) && prime(k)){
                        cout<<3<<"\n"<<i<<" "<<j<<" "<<k<<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}