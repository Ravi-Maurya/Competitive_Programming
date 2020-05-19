#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    unordered_map<string,int> scores;
    vector<pair<string,int>> arr(n);
    int max_score = 0;
    for(int i=0;i<n;i++){
        string name;
        int score;
        cin>>name>>score;
        scores[name] += score;
        arr[i] = {name,scores[name]};
    }
    for(auto it=scores.begin(); it!=scores.end(); it++)
        if(it->second > max_score)
            max_score = it->second;
    unordered_set<string> winners;
    for(auto it=scores.begin(); it!=scores.end(); it++){
        if(max_score == it->second)
            winners.insert(it->first);
    }
    int idx = n;
    string res = "";
    for(int i=0;i<n; i++){
        if(winners.count(arr[i].first) && (arr[i].second>=max_score)){
            res = arr[i].first;
            break;
        }
    }
    cout<<res<<"\n";
    return 0;
}