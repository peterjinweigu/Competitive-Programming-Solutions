// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: hamming
LANG: C++14          
*/

int n, b, d;
vector<int> please;

int cnt(int x) {
	int ret = 0;
	while (x > 0){
		ret += x % 2;
		x /= 2;
	}
	return ret;
}

bool check(vector<int> &a, int &idx) {
	for (auto j : a) {
		if (cnt(j ^ idx) < d) return false;
	}
	return true;
}

bool done;

void solve(vector<int> &my) {
	if (my.size() == n) {
		done = true;
		for (auto j : my) please.push_back(j);
		return;
	}
	if (done) return;
	for (int i = 0; i < (1 << b); i++) {
		if (check(my, i)) {
			my.push_back(i);
			solve(my);
			my.pop_back();
		}
	}

}

int main() {
	ofstream cout ("hamming.out");
    ifstream cin ("hamming.in");
    
	cin >> n >> b >> d;

	vector<int> my;
	my.push_back(0);
	
	done = false;
	solve(my);

	for (int i = 1; i <= n/10; i++) {
		for (int j = (i-1)*10; j < i*10 - 1; j++) cout << please[j] << " ";
		cout << please[i*10 - 1] << "\n"; 
	}
	if (n % 10 != 0) {
		for (int i = (n/10)*10; i < n-1; i++) cout << please[i] << " ";
		cout << please[n-1] << "\n";
	}
}

