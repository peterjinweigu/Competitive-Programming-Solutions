// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: sort3
LANG: C++14          
*/

int main() {
	ofstream cout ("sort3.out");
    ifstream cin ("sort3.in");

	int n; cin >> n;
	vector<int> v(n);
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 1) a++;
		else if (v[i] == 2) b++;
		else c++;
	}
	stack<int> two;
	for (int i = a; i < a+b; i++) {
		if (v[i] == 1) two.push(i);
	}
	stack<int> three;
	for (int i = a+b; i < n; i++) {
		if (v[i] == 1) three.push(i);
	}
	int ans = 0;
	for (int j = 0; j < a; j++) {
		if (v[j] == 2) {
			if (two.size() > 0) {
				swap(v[j], v[two.top()]);
				two.pop();
			} else {
				swap(v[j], v[three.top()]);
				three.pop();
			}
			ans++;
		}
		else if (v[j] == 3) {
			if (three.size() > 0) {
				swap(v[j], v[three.top()]);
				three.pop();
			} else {
				swap(v[j], v[two.top()]);
				two.pop();
			}
			ans++;
		}
	}
	for (int i = a; i < a+b; i++) {
		if (v[i] != 2) ans++;
	}
	cout << ans << "\n";
}

