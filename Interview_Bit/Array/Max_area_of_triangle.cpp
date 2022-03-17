int charToInt(char c){
    if(c=='r')
        return 0;
    if(c=='g')
        return 1;
    if(c=='b')
        return 2;
}

int area(int base, int height){
    return (int)ceil(((double)1 / (double)2) * base * height);
}


int Solution::solve(vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    int left[3], right[3];
    int top[3][n], bottom[3][n];
    memset(left, INT_MAX, sizeof(left));
    memset(right, INT_MIN, sizeof(right));
    memset(top, INT_MAX, sizeof(top));
    memset(bottom, INT_MIN, sizeof(bottom));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int idx = charToInt(A[i][j]);
            left[idx] = min(left[idx], j);
            right[idx] = max(right[idx], j);
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            int idx = charToInt(A[i][j]);
            top[idx][j] = min(top[idx][j], i);
            bottom[idx][j] = max(bottom[idx][j], i);
        }
    }

    int ans = 0;
    for(int i=0; i<n ; i++){
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                int z = 3 - x - y;
                if(x!=y && top[x][i]!=INT_MAX && bottom[y][i]!=INT_MIN){
                    if(left[z] != INT_MAX){
                        ans = max(ans, area(bottom[y][i] - top[x][i], i-left[z]));
                    }
                    else if(right[z] != INT_MIN){
                        ans = max(ans, area(bottom[y][i] - top[x][i], right[z]-i));
                    }
                }
            }
        }
    }
    return ans;
}
