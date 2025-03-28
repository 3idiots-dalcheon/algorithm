#include <bits/stdc++.h>
using namespace std;

int n, ans;
const int len = 1e6 + 1, inf = 1e9;
vector<int> cache;

int main() 
{
	cin >> n;

	cache = vector<int>(len);
	cache[0] = 0, cache[1] = 1;

	for (int i = 2; i <= abs(n); i++) 
		cache[i] = (cache[i - 1] + cache[i - 2]) % inf;

	ans = (n < 0 && abs(n) % 2 == 0) ? -1 : 1;
	ans = n == 0 ? 0 : ans;

	cout << ans << '\n' << cache[abs(n)] << '\n';
	return 0;
}
