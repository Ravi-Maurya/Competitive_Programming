// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        
        res = overlappedInterval(arr,n);
        
        
        for(int i=0;i<res.size();i++)
            cout << res[i].first << " " << res[i].second << " " ;
            
        cout<<endl;
    }
}
// } Driver Code Ends
//User function template for C++

// n : size of the array
// vec : given vector pair containing intervals
bool compare(pair<int,int> x, pair<int,int> y){
    if(x.first==y.first)
        return x.second<=y.second;
    return (x.first < y.first);
} 
vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    if(n==1)
        return vec;
    sort(vec.begin(), vec.end(),compare);
    vector<pair<int,int>> res;
    int i=0,j=1;
    res.push_back(vec[0]);
    while(j<n){
        if(res[i].second>=vec[j].first){
            res[i].first = min(res[i].first, vec[j].first);
            res[i].second = max(res[i].second, vec[j].second);
            j++;
        }
        else{
            res.push_back(vec[j]);
            i++;
            j++;
        }
    }
    return res;
}