class Solution {
private:
	vector<int> visit;
	int n;
public:
	void dfs(vector<vector<int>>& M, int cur){
		if(visit[cur]==1){
			return;
		}
		visit[cur]=1;
		for(int j=0;j<n;j++){
			if(M[cur][j]==1 && visit[j]==0){
				dfs(M,j);
			}
		}
	}
	int findCircleNum(vector<vector<int>>& M) {
		n=M.size();
		int res=0;
		visit=vector<int>(n,0);
		for(int i=0;i<n;i++){
			if(visit[i]==1){
				continue;
			}
			res++;
			dfs(M,i);
		}
		return res;
	}
};