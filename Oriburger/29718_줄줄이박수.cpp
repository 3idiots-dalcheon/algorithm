#include <bits/stdc++.h>
using namespace std;

int n, m, a, sum = 0, ans = 0;
int board[2001][2001];
queue<int> q;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];
	cin>>a;
	
	for(int i=0; i<m; i++)
	{
		int tmp = 0;
		
		if(q.size() >= a)
		{
			sum -= q.front();
			q.pop();
		}
		
		for(int j=0; j<n; j++)
		{
			tmp += board[j][i];
		}
		q.push(tmp);
		sum += tmp;
		
		ans = max(ans, sum);
	}
	cout<<ans<<'\n';
	
	return 0;
}
