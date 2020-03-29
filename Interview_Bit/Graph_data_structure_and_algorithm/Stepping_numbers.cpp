vector<int> res;
int x,y;

void bfs(long long int n){
    if (n>y)
        return;
    if(n>=x)
        res.push_back(n);
    int ld = n%10;
    if(ld==0)
        bfs(n*10 + 1);
    else{
        if(ld==9)
            bfs(n*10 + 8);
        else{
            bfs(n*10 + ld - 1);
            bfs(n*10 + ld + 1);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    res.clear();
    if(A>B)
        return res;
    x = A;
    y = B;
    if(A==0)
        res.push_back(0);
    for(int i=1;i<10;i++)
        bfs(i);
    if(!res.empty())
        sort(res.begin(),res.end());
    return res;
}
