#include <bits/stdc++.h>
using namespace std;

string board[51];
int n, m, ans = 1e9;

int getcount(char pivot, int st, int len)
{
	int ret = 0;
	for (int i = st; i < st+len; i++)
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != pivot)
				ret++;
		}
	return ret;
}

int main() 
{
	cin>>n>>m;
	for (int i = 0; i < n; i++)
		cin>>board[i];
				
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
		{
			int k = n - i - j;
			if(k > 0)
			{
				ans = min(ans, getcount('W', 0, i) + getcount('B', i, j) + getcount('R', i+j, k));
			}
		}

	cout<<ans<<'\n';
	
	return 0;
}
