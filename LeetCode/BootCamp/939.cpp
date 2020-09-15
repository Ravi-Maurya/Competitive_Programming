class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map <int,set<int> > x;
        vector <int> v;
        int ans=INT_MAX;
        for(auto p:points)x[p[0]].insert(p[1]);
        for(auto it=x.begin();it!=x.end();it++){
            for(auto it2=next(it,1);it2!=x.end();it2++){
                
                if(it2==it)
                    continue;
                
                v.clear();
                
                for(auto y:it->second)
                    if(it2->second.find(y)!=it2->second.end())
                        v.push_back(y);
                
                if(v.size()<2)
                    continue;
                
                int temp=INT_MAX;
                for(int i=1;i<v.size();i++)
                    temp=min(temp,v[i]-v[i-1]);
                
                ans=min(ans,temp*abs(it->first-it2->first));
            }
        }
        return ans==INT_MAX?0:ans;
    }
};