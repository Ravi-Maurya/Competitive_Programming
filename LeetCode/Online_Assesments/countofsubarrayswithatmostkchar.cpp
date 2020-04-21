#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
int most_k(vector<int> &s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<int, int> table;
    int num = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {
        table[s[i]]++;
        while (table.size() > k) {
            table[s[left]]--;
            if (table[s[left]] == 0) {
                table.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;
    }
    return num;
}

int exact_k(vector<int> &s, int k) {
    return most_k(s, k) - most_k(s, k - 1);
}
int subarraysWithKDistinct(vector<int>& A, int K) {
    return exact_k(A,K);
}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}