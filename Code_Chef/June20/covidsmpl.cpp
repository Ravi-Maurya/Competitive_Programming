#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,p;
        vector<int> arr;
        cin>>n>>p;
        ll infected = 0, total;
        ll r1 = 1, r2 = 1, c1 = 1, c2  = 1,val;
        cout<<1 <<" "<<1 <<" "<<1 <<" "<< n <<" "<< n <<endl;
        cin>>total;
        for(ll i = 1; i<(n*n); i++){
            if(total == infected){
                arr.push_back(0);
                continue;
            }
            cout<<1 <<" "<<r1 <<" "<<c1 <<" "<< r2 <<" "<< c2 <<endl;
            cin>>val;
            if(c1==n){
                c1 = 1;
                c2 = 1;
                r1++;
                r2++;
            }
            else{
                c1++;
                c2++;
            }
            if(val>=0){
                arr.push_back(val);
                if(val==1)
                    infected++;
            }
            else{
                return 0;
            }
        }
        cout<<2<<endl;
        for(ll i= 0; i<(n*n); i++){
            cout<< arr[i] << " ";
            if((i+1)%n == 0)
                cout<<endl;
        }
        arr.clear();
        cin>>val;
        if(val==1)
            continue;
        else
            return 0;
    }
    return 0;
}
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL); cout.tie(NULL);
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n,p,x;
//         cin>>n>>p;
//         ll arr[n][n];
//         memset(arr,0,sizeof(arr));
//         for(ll i = 0; i < n; i++){
//             cout<< 1 << " " << (i+1) << " " << 1 << " " << (i+1) << " " << n << endl;
//             cin>> x;
//             ll counter = 0;
//             ll total = x;
//             if(total == n){
//                 memset(arr,1,sizeof(arr));
//                 break;
//             }
//             if(total == 0){
//                 break;
//             }
//             for(ll j = 0; j<n; j++){
//                 cout<< 1 << " " << (i+1) << " " << (j+1) << " " << (i+1) << " " << (j+1) << endl;
//                 cin>> x;
//                 arr[i][j] = x;
//                 if(x==1)
//                     counter++;
//                 if(counter == total)
//                     break;
//                 if((n-j-1) == (total - counter)){
//                     for(ll k = j+1; k<n; k++)
//                         arr[i][k] = 1;
//                     break;
//                 }
//             }
//         }
//         cout << 2 <<endl;
//         for(ll i = 0; i<n; i++){
//             for(ll j = 0; j<n; j++){
//                 cout<< arr[i][j] << " ";
//             }
//             cout<< endl;
//         }
//         cin >> x;
//         if(x==-1)
//             break;
//     }
//     return 0;
// }