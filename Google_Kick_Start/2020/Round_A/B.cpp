#include <bits/stdc++.h>
using namespace std;
using namespace std;
typedef std::stack<int> Stack;
typedef std::vector<int> Array;

void find_max (Stack stacks[], int N, Array &arr, int M) {
arr.resize(M+1, 0);
for (int i = 0; i < N; ++i) {
int index = 0;
int sum = 0;
while (!stacks[i].empty()) {
sum += stacks[i].top(); ++index;
if (arr[index] < sum) arr[index] = sum;
stacks[i].pop();
}
} //end of all stacks iteration
}

int find_max_sum (Array &arr, int M) {
int max_sum = 0;
for (int ind = 0; ind < M/2; ++ind) {
int first = ind;
int last = M - first;
if (arr[first] + arr[last] > max_sum) max_sum = arr[first] + arr[last];
}
return max_sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    for(int test =1; test<=T;test++){
        int n,k,p;
        cin>>n>>k>>p;
        vector <vector<int>> stacks(n, vector<int>(k));
        for(int i=0;i<n;i++)
            for(int j=k-1;j>=0;j--)
                cin>>stacks[i][j];
        cout<<"Case #"<<test<<": "<<maxSum(stacks,p,n,k)<<"\n";
    }
    return 0;
}