string Solution::multiple(int A) {
    vector<int> flag(A), parent(A), value(A);
    string res="";
    queue<int> q;
    int temp = 1%A;
    q.push(temp);
    flag[temp] = 1;
    value[temp] = 1;
    while(true){
        int p = q.front();
        q.pop();
        
        if(p==0){
            res += (char)(value[p]+'0');
            p = parent[p];
            while(p){
                res += (char)(value[p]+'0');
                p = parent[p];
            }
            reverse(res.begin(),res.end());
            return res;
        }
        
        int x = (p*10)%A;
        if(flag[x]==0){
            q.push(x);
            flag[x]=1;
            parent[x] = p;
            value[x] = 0;
        }
        x = (1+ p*10)%A;
        if(flag[x]==0){
            q.push(x);
            flag[x]=1;
            parent[x] = p;
            value[x] = 1;
        }
    }
}
