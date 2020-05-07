class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int x, int y, int x2, int y2, int tot, int cnt, int& ans, vector<vector<int>>& a, vector<vector<int>>& vis){
        if(tot==cnt && x==x2 && y==y2){
            ans++;
            return;
        }
        int m = a.size();
        int n = a[0].size();
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<0||yy<0||xx>=m||yy>=n||a[xx][yy]==-1||a[xx][yy]==1||vis[xx][yy]==1) continue;
            if(a[xx][yy]==0) tot++;
            dfs(xx,yy,x2,y2,tot,cnt,ans,a,vis);
            if(a[xx][yy]==0) tot--;
        }
        vis[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        int cnt = 0;
        int x1=-1,y1=-1,x2=-1,y2=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0) cnt++;
                if(a[i][j]==1){
                    x1=i;y1=j;
                }
                if(a[i][j]==2){
                    x2=i;y2=j;
                }
            }
        }
        int ans = 0;
        dfs(x1,y1,x2,y2,0,cnt,ans,a,vis);
        return ans;
    }
};