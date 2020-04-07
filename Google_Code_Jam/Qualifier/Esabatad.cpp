#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
void complement(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        arr[i] = arr[i]^1;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    set<pair<int,int>> set1,set2;
    set1.insert({0,0});
    set1.insert({1,1});
    set2.insert({0,1});
    set2.insert({1,0});
    int t,b;
    cin>>t>>b;
    if(b==10){
        for(int test = 0; test<t;test++){
            string s = "";
            for(int i=1;i<=10;i++){
                cout<<i<<endl;
                fflush(stdout);
                int bit;
                cin>>bit;
                s += to_string(bit);
            }
            cout<<s<<endl;
            fflush(stdout);
            char op;
            cin>>op;
            if(op=='N')
                return 0;
        }
    }
    else{
        for(int test = 0; test<t;test++){
            string s = "";
            vector<int> left;
            vector<int> right;
            int s1 = -1,s2 = -1;
            for(int i=1;i<=5;i++){
                cout<<i<<endl;
                fflush(stdout);
                int bit;
                cin>>bit;
                left.push_back(bit);
                cout<<b-i+1<<endl;
                fflush(stdout);
                cin>>bit;
                right.push_back(bit);
                if(i==1){
                    s1 = i;
                }
                else if(s2==-1){
                    pair<int,int> tmp2 = {left[i-1],right[i-1]}, tmp1= {left[s1-1],right[s1-1]};
                    if((set1.find(tmp1)!=set1.end() && set2.find(tmp2)!=set2.end()) || (set2.find(tmp1)!=set2.end() && set1.find(tmp2)!=set1.end())){
                        s2 = i;
                    }
                }
            }
            while(left.size() + right.size() < b){
                if(s2==-1){
                    int bit;
                    cout<<s1<<endl;
                    fflush(stdout);
                    cin>>bit;
                    cout<<s1<<endl;
                    fflush(stdout);
                    cin>>bit;
                    if(left[s1-1]!=bit){
                        complement(left);
                        complement(right);
                    }
                    int kl = left.size();
                    for(int i=kl+1;i<=min(kl+4,b/2);i++){
                        cout<<i<<endl;
                        fflush(stdout);
                        cin>>bit;
                        left.push_back(bit);
                        cout<<b-i+1<<endl;
                        fflush(stdout);
                        cin>>bit;
                        right.push_back(bit);
                        if(s2==-1){
                            pair<int,int> tmp2 = {left[i-1],right[i-1]}, tmp1= {left[s1-1],right[s1-1]};
                            if((set1.find(tmp1)!=set1.end() && set2.find(tmp2)!=set2.end()) || (set2.find(tmp1)!=set2.end() && set1.find(tmp2)!=set1.end()))
                                s2 = i;
                        }
                    }
                }
                else{
                    if(set2.find(make_pair(left[s1-1],right[s1-1]))!=set2.end())
                        swap(s1,s2);
                    int bit1,bit2;
                    cout<<s1<<" "<<s2<<" "<<endl;
                    cout<<s1<<endl;
                    fflush(stdout);
                    cin>>bit1;
                    cout<<s2<<endl;
                    fflush(stdout);
                    cin>>bit2;
                    // TT->N, TF->R, FT->RC, FF->C
                    if(bit1==left[s1-1] && bit2!=left[s2-1]){
                        swap(left,right);
                    }
                    else if(bit1!=left[s1-1] && bit2==left[s2-1]){
                        swap(left,right);
                        complement(left);
                        complement(right);
                    }
                    else if (bit1!=left[s1-1] && bit2!=left[s2-1]){
                        complement(left);
                        complement(right);
                    }
                    int kl = left.size();
                    for(int i=kl+1;i<=min(kl+4,b/2);i++){
                        int bit;
                        cout<<i<<endl;
                        fflush(stdout);
                        cin>>bit;
                        left.push_back(bit);
                        cout<<b-i+1<<endl;
                        fflush(stdout);
                        cin>>bit;
                        right.push_back(bit);
                    }
                }
            }
            for(int i=0;i<b/2;i++)
                s += to_string(left[i]);
            for(int i= (b/2)-1 ;i>=0;i--)
                s += to_string(right[i]);
            cout<<s<<endl;
            fflush(stdout);
            char op;
            cin>>op;
            if(op=='N')
                return 0;
        }
    }
    return 0;
}