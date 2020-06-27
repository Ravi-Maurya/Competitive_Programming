class Solution {
public:
    vector<int> dirs = {-1,0,1,0,-1};
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int curr){
        if(i>=image.size() || j>=image[0].size() || i<0 || j<0 || image[i][j]!=curr)
            return;
        image[i][j] = newColor;
        for(int k=0; k<4;k++)
            dfs(image,i+dirs[k],j+dirs[k+1],newColor,curr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)
            return image;
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};