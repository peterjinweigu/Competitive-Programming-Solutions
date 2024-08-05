// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500010
#define MOD 998244353
typedef long long ll;
typedef pair<int, ll> pi;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt; tt = 1;
	while (tt--) {
		// dude I AM SO stupid man, I swear I need to be punished for this behaviour
		// EVERY bitmask dp problem involves
		// iterating over masks, either where order matters or it dosent
		// if order does the state is usually dp[i][mask]
		// if it dosent, some sort of SOS dp or state by state comparison is involved
		// but ALL the time, you see a problem with some n <= 28 ish you should be
		// iterating over masks
		// and immedaitely think, ok if I were to iterate over masks
		// how would I check their validity in constant time
		// in this case suppose I have some alphabet, and I would like to introduce a new last letter
		// this would cause breaks wherever my new letter is proceeded by a previous letter
		// ok this observation is sorta trivial/not intuitive
		// like i look at this problem in a way where checking takes N time
		// specifically i need to look at orders
		// but if I solved the bronze problem, i would have seen the more trivial obersvation??
		// which is that the alphabet ends when the next letter is before me in the alphabet
		// so the total number of alphabests is the total times that happens given an order
		// and then bitmasking is obvious after that
		// when we bitmask, we notice that the order of the previous letters does not matter
		// as long as the final answer is minimal
		// because introducing a new letter only considers that all the letters are prevoous
		// and does not care about their own order
		string s; cin >> s;
		int n = s.size();
		map<char, int> mp;
		int rg = 0;
		for (int i = 0; i < n; i++) {
			if (mp.find(s[i]) == mp.end()) mp[s[i]] = rg++;
		}
		vector<int> cnt[rg];
		for (int i = 0; i < rg; i++) cnt[i].resize(rg, 0);
		for (int i = 0; i < n-1; i++) {
			int x = mp[s[i]];
			int y = mp[s[i+1]];
			cnt[y][x]++;
		}
		vector<int> dp((1 << rg), 1e9);
		dp[0] = 1;
		for (int mask = 0; mask < (1 << rg); mask++) {
			for (int i = 0; i < rg; i++) {
				if ((1 << i) & mask) continue;
				int cur = dp[mask] + cnt[i][i];
				for (int j = 0; j < rg; j++) {
					if ((1 << j) & mask) cur += cnt[j][i];
				}
				dp[mask | (1 << i)] = min(dp[mask | (1 << i)], cur);
			}
		}
		cout << dp[(1 << rg)-1] << "\n";
	}
}