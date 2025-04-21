#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cache = {1, 2, 3, 5, 8}; 

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 5; i < n; i++)
	{
		cache.push_back((cache[i - 1] + cache[i - 2]) % 10);
	}
	cout << cache[n - 1] << '\n';
	
	return 0;
}
