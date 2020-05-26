#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
	cin >> n;
    if (n == 2) {
		cout << "1\n";
		return 0;
	}
	if (n % 2 == 0) {
		cout << "2\n";
		return 0;
	}
	bool prime = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	if (prime) {
		cout << "1\n";
	} else {
		bool prime = true;
		int m = n - 2;
		for (int i = 2; i * i <= m; i++) {
			if (m % i == 0) {
				prime = false;
				break;
			}
		}
		if (prime)
			cout << "2\n";
		else
			cout << "3\n";
	}
	return 0;
}