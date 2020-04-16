#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

map<pair<int,int>,int> dpwest,dpeast,dpnorth,dpsouth;
map<pair<int,int>,int> vis;
pair<int,int> move_west(pair<int,int> p){
    if(vis[p] == 0){
        vis[p] = 1;
        return p;
    }
    if(dpwest[p] == 0){
        pair<int,int> ans = move_west({p.first,p.second - 1});
        dpwest[p] = ans.second;
    }
    else{
        pair<int,int> ans = move_west({p.first,dpwest[p]});
        dpwest[p] = ans.second;

    }
    return {p.first,dpwest[p]};
}
pair<int,int> move_east(pair<int,int> p){
    if(vis[p] == 0){
        vis[p] = 1;
        return p;
    }
    if(dpeast[p] == 0){
        pair<int,int> ans = move_east({p.first,p.second + 1});
        dpeast[p] = ans.second;
    }
    else{
        pair<int,int> ans = move_east({p.first,dpeast[p]});
        dpeast[p] = ans.second;

    }
    return {p.first,dpeast[p]};
}
pair<int,int> move_south(pair<int,int> p){
    if(vis[p] == 0){
        vis[p] = 1;
        return p;
    }
    if(dpsouth[p] == 0){
        pair<int,int> ans = move_south({p.first + 1,p.second});
        dpsouth[p] = ans.first;
    }
    else{
        pair<int,int> ans = move_south({dpsouth[p],p.second});
        dpsouth[p] = ans.first;

    }
    return {dpsouth[p],p.second};
}
pair<int,int> move_north(pair<int,int> p){
    if(vis[p] == 0){
        vis[p] = 1;
        return p;
    }
    if(dpnorth[p] == 0){
        pair<int,int> ans = move_north({p.first - 1,p.second});
        dpnorth[p] = ans.first;
    }
    else{
        pair<int,int> ans = move_north({dpnorth[p],p.second});
        dpnorth[p] = ans.first;

    }
    return {dpnorth[p],p.second};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,r,c,sr,sc;
        cin>>n>>r>>c>>sr>>sc;
        dpwest.clear();
        dpeast.clear();
        dpnorth.clear();
        dpsouth.clear();
        vis.clear();
        vis[{sr,sc}] = 1;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            pair<int,int> p;
            if(c == 'N')
                p = move_north({sr-1,sc});
            if(c == 'S')
                p = move_south({sr+1,sc});
            if(c == 'E')
                p = move_east({sr,sc+1});
            if(c == 'W')
                p = move_west({sr,sc-1});
            sr = p.first;
            sc = p.second;
        }
        cout<<"Case #"<<test<<": "<<sr<<" "<<sc<<"\n";
    }
    return 0;
}