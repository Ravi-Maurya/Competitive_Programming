#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
string expression;
vector<int> recursive(int i, int j){
    if(i==j)
        return {expression[i]=='T', expression[i]=='F'};
    int t = 0, f = 0;
    for(int k=i+1; k<j; k+=2){
        char op = expression[k];
        if(op=='|'){
            t += (recursive(i,k-1)[0] * recursive(k+1,j)[0]) + (recursive(i,k-1)[1] * recursive(k+1,j)[0]) + (recursive(i,k-1)[0] * recursive(k+1,j)[1]); // TT, TF, FT
            f += ((recursive(i,k-1)[1] * recursive(k+1,j)[1])); // FF
        }
        else if(op=='&'){
            f += (recursive(i,k-1)[1] * recursive(k+1,j)[1]) + (recursive(i,k-1)[1] * recursive(k+1,j)[0]) + (recursive(i,k-1)[0] * recursive(k+1,j)[1]); // FF, TF, FT
            t += ((recursive(i,k-1)[0] * recursive(k+1,j)[0])); // TT
        }
        else{
            t += (recursive(i,k-1)[1] * recursive(k+1,j)[0]) + (recursive(i,k-1)[0] * recursive(k+1,j)[1]); // TF, FT
            f += (recursive(i,k-1)[0] * recursive(k+1,j)[0]) + (recursive(i,k-1)[1] * recursive(k+1,j)[1]); // TT, FF
        }
    }
    return {t,f};
}

int parenthesis(string& symbols, string& op){
    int n = symbols.size();
    vector<vector<int>> T(n,vector<int>(n,0)),F(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        if(symbols[i]=='T')
            T[i][i] = 1;
        else
            F[i][i] = 1;
    }
    for(int length = 2; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            for(int k=i;k<j;k++){
                if(op[k]=='|'){
                    T[i][j] += (T[i][k]*T[k+1][j] + F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]); // TT, FT, TF
                    F[i][j] += F[i][k]*F[k+1][j];
                }
                else if(op[k]=='&'){
                    F[i][j] += (F[i][k]*F[k+1][j] + F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]); // FF, FT, TF
                    T[i][j] += T[i][k]*T[k+1][j];
                }
                else{
                    T[i][j] += (F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]); // FT, TF
                    F[i][j] += (T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]); // TT, FF
                }
            }
        }
    }
    return T[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>expression;
    cout<<recursive(0,expression.size()-1)[0]<<"\n";
    string sym, op;
    cin>>sym>>op;
    cout<<parenthesis(sym,op);
    return 0;
}