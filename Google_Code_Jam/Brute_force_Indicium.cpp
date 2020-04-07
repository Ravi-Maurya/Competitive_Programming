#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
void rotate_array(vector<int>& row){
    int n = row.size();
    int tmp = row[n-1];
    row.pop_back();
    row.insert(row.begin(),tmp);
}

void swap_values(vector<vector<int>>& matrix, int n, int x, int y){
    if(x==-1)
        return;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==x){
                matrix[i][j] = y;
            }
            else if(matrix[i][j]==y){
                matrix[i][j] = x;
            }
        }
    }
    return;
}

int calculate(int k,int n){
    int t = k/(n/2);
    return (t/2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    int udx = -1, udy = 1;
    int ldx = 1, ldy = -1;
    cin>>t;
    for(int test = 1; test<=t; test++){
        int n,k;
        cin>>n>>k;
        if(!(n<=k && k<=n*n) || (k==3 && n==2) || (n==3 && k%n!=0) || (n==4 && (k==5 || k==15)) || (n==5 && (k==6 || k==24)) || (n>5))
            cout<<"Case #"<<test<<": "<<"IMPOSSIBLE"<<endl;
        else if(k%n==0){
            vector<vector<int>> matrix;
            vector<int> row;
            for(int i = k/n; i<=n; i++)
                row.push_back(i);
            for(int i=1;i<k/n;i++)
                row.push_back(i);
            for(int i=0;i<n;i++){
                matrix.push_back(row);
                rotate_array(row);
            }
            cout<<"Case #"<<test<<": "<<"POSSIBLE"<<endl;
            for(int i = 0; i<n;i++){
                for(int j=0; j<n;j++){
                    cout<<matrix[i][j];
                    if((i <=(n-1)) && (j <(n-1)))
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        else if(n==4 && k%2==0){
            vector<vector<int>> matrix;
            int x = calculate(k,n);
            vector<vector<int>> a(n,vector<int>(n,0));
            for(int i=0;i<n;i+=2){
                a[i][i] = x;
                int tmp1 = i, tmp2 = i;
                while((tmp1+udx >=0) && (tmp2+udy<n)){
                    tmp1 += udx;
                    tmp2 += udy;
                    a[tmp1][tmp2] = a[i][i];
                }
                tmp1 = i, tmp2 = i;
                while((tmp1+ldx<n) && (tmp2+ldy>=0)){
                    tmp1 += ldx;
                    tmp2 += ldy;
                    a[tmp1][tmp2] = a[i][i];
                }
                a[i+1][i+1] = x+1;
                tmp1 = i+1, tmp2 = i+1;
                while((tmp1+udx >=0) && (tmp2+udy<n)){
                    tmp1 += udx;
                    tmp2 += udy;
                    a[tmp1][tmp2] = a[i+1][i+1];
                }
                tmp1 = i+1, tmp2 = i+1;
                while((tmp1+ldx<n) && (tmp2+ldy>=0)){
                    tmp1 += ldx;
                    tmp2 += ldy;
                    a[tmp1][tmp2] = a[i+1][i+1];
                }
            }
            vector<int> remaining;
            for(int i=1;i<=n;i++)
                if((i != x) && (i != x+1))
                    remaining.push_back(i);
            for(int i=1;i<n;i+=2){
                int num = remaining[(int)(i/2)];
                int stx = i, sty = 0;
                int enx = n-1, eny = n-1-i;
                while(stx>=0 && sty<n){
                    a[stx][sty] = num;
                    a[enx][eny] = num;
                    stx += udx;
                    enx += udx;
                    sty += udy;
                    eny += udy;
                }
            }
            matrix = a;
            cout<<"Case #"<<test<<": "<<"POSSIBLE"<<endl;
            for(int i = 0; i<n;i++){
                for(int j=0; j<n;j++){
                    cout<<matrix[i][j];
                    if((i <=(n-1)) && (j <(n-1)))
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        else if(n==4 && k%2==1){
            vector<vector<int>> matrix(4,vector<int>(4,0));
            int x;
            if(10>k)
                x = 1;
            else
                x = 4;
            int x1 = (k - 2*x)/2;
            int x2 = x1 + 1;
            int x3;
            for(int i=1;i<=4;i++)
                if(i!=x1 && i!=x2 && i!=x)
                    x3 = i;
            matrix[0][0] = matrix[1][2] = matrix[2][3] = matrix[3][1] = x1;
            matrix[0][1] = matrix[1][3] = matrix[2][2] = matrix[3][0] = x2;
            matrix[0][3] = matrix[1][0] = matrix[2][1] = matrix[3][2] = x3;
            matrix[0][2] = matrix[1][1] = matrix[2][0] = matrix[3][3] = x;
            cout<<"Case #"<<test<<": "<<"POSSIBLE"<<endl;
            for(int i = 0; i<n;i++){
                for(int j=0; j<n;j++){
                    cout<<matrix[i][j];
                    if((i <=(n-1)) && (j <(n-1)))
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        else if (n==5){
            vector<vector<int>> matrix = {{1,3,4,5,2},{5,2,3,1,4},{2,4,1,3,5},{4,1,5,2,3},{3,5,2,4,1}};
            switch (k){
                case 8:
                    swap_values(matrix,5, 1,2);
                    break;
                case 9:
                    swap_values(matrix,5,2,3);
                    break;
                case 11:
                    swap_values(matrix,5,1,2);
                    swap_values(matrix,5,2,3);
                    break;
                case 12:
                    swap_values(matrix,5,1,2);
                    swap_values(matrix,5,1,3);
                    break;
                case 13:
                    swap_values(matrix,5,1,5);
                    break;
                case 14:
                    swap_values(matrix,5,1,2);
                    swap_values(matrix,5,1,4);
                    break;
                case 16:
                    swap_values(matrix,5,1,2);
                    swap_values(matrix,5,1,5);
                    break;
                case 17:
                    swap_values(matrix,5,1,2);
                    swap_values(matrix,5,2,5);
                    break;
                case 18:
                    swap_values(matrix,5,1,4);
                    swap_values(matrix,5,2,3);
                    break;
                case 19:
                    swap_values(matrix,5,1,3);
                    swap_values(matrix,5,2,5);
                    break;
                case 21:
                    swap_values(matrix,5,1,5);
                    swap_values(matrix,5,2,3);
                    break;
                case 22:
                    swap_values(matrix,5,1,4);
                    swap_values(matrix,5,2,5);
                    break;
                case 23:
                    swap_values(matrix,5,1,5);
                    swap_values(matrix,5,2,4);
                    break;
                default:
                    break;
            }
            cout<<"Case #"<<test<<": "<<"POSSIBLE"<<endl;
            for(int i = 0; i<n;i++){
                for(int j=0; j<n;j++){
                    cout<<matrix[i][j];
                    if((i <=(n-1)) && (j <(n-1)))
                        cout<<" ";
                }
                cout<<endl;
            }

        }
    }
    return 0;
}