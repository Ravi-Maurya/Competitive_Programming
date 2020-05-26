#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int x,y;
	cin>>x>>y;
    if(x==0 && y==0 || x==1 && y==0){
        cout<<0<<"\n";
    }
	else if(x>=0){
        if(y>=0){
			if(y<=x)
				cout<<(4*(x-1))+1<<endl;
			else
				cout<<(4*(y-1))+2<<endl;
		}
		else{
			y=abs(y);
			if(x-y>1)
				cout<<(4*(x-1))+1<<endl;
			else
				cout<<(4*y)<<endl;
		}
	}
	else{
		x=abs(x);
		if(y>=0){
			if(y<x)
				cout<<(4*(x-1))+3<<endl;
			else
				cout<<(4*(y-1))+2<<endl;
		}
		else{
			x=abs(x);
			y=abs(y);
			if(y<=x)
				cout<<(4*(x-1))+3<<endl;
			else
				cout<<(4*y)<<endl;
		}
	}
    return 0;
}