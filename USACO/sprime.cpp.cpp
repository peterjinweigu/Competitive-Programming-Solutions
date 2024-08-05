// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: sprime
LANG: C++14          
*/

vector<string> p[9];

bool prime(int &num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	ofstream cout ("sprime.out");
    ifstream cin ("sprime.in");

	int n; cin >> n;
	p[0].push_back("");
	for (int i = 1; i <= n; i++) {
		for (string cur : p[i-1]) {
			for (int j = 0; j <= 9; j++) {
				string temp = cur + (char)(j + '0');
				int x = stoi(temp);
				if (prime(x)) p[i].push_back(temp);
			}
		}
	}
	for (auto j : p[n]) cout << j << "\n";
}

	