#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;
// struct Node{
//     ll first;
//     ll second;
//     Node(){
//         first = 0;
//         second = 0;
//     }
//     void init(ll o, ll s){
//         first = o;
//         second = s;
//     }
//     void merge(Node a, Node b){
//         first = a.first + b.first;
//         second = a.second + b.second;
//     }
// };

// class SegmentTree{
// public:
//     vector<ll> arr1,arr2;
//     vector<Node> tree;
//     ll n;
//     SegmentTree(vector<ll>& input1, vector<ll>& input2){
//         arr1.clear();
//         arr2.clear();
//         tree.clear();
//         arr1 = input1;
//         arr2 = input2;
//         n = input1.size();
//         tree.resize(4*n);
//         buildTree(0,n-1,1);
//     }
    
//     void buildTree(ll st, ll en, ll idx){
//         if(st==en){
//             tree[idx].init(arr1[st], arr2[st]);
//             return;
//         }
//         ll mid = st + (en-st)/2;
//         buildTree(st,mid,2*idx);
//         buildTree(mid+1,en,2*idx+1);
//         tree[idx].merge(tree[2*idx], tree[2*idx + 1]);
//         return;
//     }

//     Node query(ll st, ll en, ll l, ll r, ll idx){ // intitially(0,n-1,i,j,1)
//         Node res;
//         if(st>en || st>r || en<l || l>r)
//             return res;
//         if(st>=l && en<=r)
//             return tree[idx];
//         ll mid = st + (en-st)/2;
//         Node left = query(st,mid,l,r,2*idx);
//         Node right = query(mid+1,en,l,r,2*idx+1);
//         res.init(left.first + right.first, left.second + right.second);
//         return res;
//     }
// };


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr1(n),arr2;
    for(ll i=0; i<n; i++)
        cin>>arr1[i];
    arr2 = arr1;
    sort(arr2.begin(),arr2.end());
    for(int i=1;i<n;i++){
        arr1[i] += arr1[i-1];
        arr2[i] += arr2[i-1];
    }
    // SegmentTree st = SegmentTree(arr1, arr2);
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        ll l,r,type;
        cin>>type>>l>>r;
        // auto res = st.query(0,n-1,l-1,r-1,1);
        if(type == 1)
            cout<<(arr1[r-1] - ( (l==1) ? 0 : arr1[l-2]))<<"\n";
        else
            cout<<(arr2[r-1] - ( (l==1) ? 0 : arr2[l-2]))<<"\n";
    }
    return 0;
}