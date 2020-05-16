#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        string res = "";
        double d,s;
        cin>>d>>s;
        vector<double> coding_slot(s), eating_slot(s);
        multiset<pair<double,double>> mst;
        double a = 0,b=0;
        for(int i=0; i<s; i++){
            cin>>coding_slot[i]>>eating_slot[i];
            double tmp = eating_slot[i]/coding_slot[i];
            mst.insert({tmp,coding_slot[i]});
            a+=coding_slot[i];
        }
        vector<pair<pair<double,double>,int>> days(d);
        for(int i=0; i<d; i++){
            cin>>days[i].first.first>>days[i].first.second;
            days[i].second = i;
        }
        sort(days.begin(), days.end());
        reverse(days.begin(), days.end());
        res.resize(d);
        for(int i=0; i<d ; i++){
            double c = days[i].first.first, e = days[i].first.second;
            while (!mst.empty() && a>c){
                double tmp = a-c;
                auto x = *mst.rbegin();
                mst.erase(mst.find(x));
                if(x.second < tmp){
                    b+=x.second*x.first;
                    a-=x.second;
                }
                else{
                    b+=tmp*x.first;
                    a-=tmp;
                    mst.insert({x.first, x.second - tmp});
                }
            }
            if((a>=c || abs(a-c)<1e-9) && (b>=e || abs(b-e)<1e-9))
                res[days[i].second] = 'Y';
            else
                res[days[i].second] = 'N';
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}