#include <bits/stdc++.h>
using namespace std;

int matrix[60][60], n, k, t;
vector<vector<bool>> row_safe(60,vector<bool>(60,false)), col_safe(60,vector<bool>(60,false));
bool possible = false;

void recursive(int row, int col, int m) {
    if ((row == n) && (col == n + 1) && (m == k) && !possible) {
        possible = true;
        cout << "Case #" << t << ": " << "POSSIBLE"<<endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout <<endl;
        }
        return;
    } else if (row > n) {
        return;
    } else if (col > n) {
        recursive(row + 1, 1, m);
    }
    for (int i = 1; i <= n && !possible; ++i) {
        if (!row_safe[row][i] && !col_safe[col][i]) {
            row_safe[row][i] = col_safe[col][i] = true;
            if (row == col) {
                m += i;
            }
            matrix[row][col] = i;

            recursive(row, col + 1, m);

            row_safe[row][i] = col_safe[col][i] = false;
            if (row == col) {
                m -= i;
            }
            matrix[row][col] = 0;
        }
    }
}

int main() {
    int T;
    cin>>T;
    for (t = 1; t <= T; ++t) {
        cin>>n>>k;
        recursive(1, 1, 0);
        if (!possible) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE"<<endl;
        }
        possible = false;
    }
    return 0;
}