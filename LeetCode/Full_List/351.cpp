class Solution {
public:
    bool visited[10];
    bool valid(int idx, int last){
        if(visited[idx])
            return false;
        if(last==-1)
            return true;
        if((idx+last)%2 == 1 )
            return true;
        int mid = (idx + last)/2;
        if(mid==4)
            return visited[mid];
        if((idx%3 != last%3) && (idx/3 != last/3))
            return true;
        return visited[mid];
    }
    int dfs(int parent, int len){
        if(len==0)
            return 1;
        int res = 0;
        for(int i=0; i<9; i++){
            if(valid(i,parent)){
                visited[i] = true;
                res += dfs(i,len-1);
                visited[i] = false;
            }
        }
        return res;
    }
    
    int numberOfPatterns(int m, int n) {
        int res = 0;
        memset(visited,false,sizeof(visited));
        for(int i=m; i<=n; i++){
            res += dfs(-1,i);
            memset(visited,false,sizeof(visited));
        }
        return res;
    }
};