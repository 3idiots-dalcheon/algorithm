#include <bits/stdc++.h>
using namespace std;

int r, c;
char island[13][13];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>r>>c;

	for (int i = 1; i <= r; i++)
		for(int j=1; j <= c; j++)
			cin>>island[i][j];		

	for (int i = 1; i<=r; i++)
	{
		for(int j=1; j<=c; j++)
		{
			if(island[i][j] != 'X') continue;

			int cnt = 0;
			for(int d=0; d<4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if(island[ny][nx] != 'X' && island[ny][nx] != ' ') cnt++;
			}
			if(cnt >= 3) island[i][j] = ' ';
		}
	}
	
	int sy, sx, fy, fx;
	sy = sx = 1e9;
	fy = fx = 0;
	
	for (int i=1; i<=r; i++)
		for(int j=1; j<=c; j++)
		{
			sy = min(sy, (int)(island[i][j] == 'X' ? i : 1e9));
			sx = min(sx, (int)(island[i][j] == 'X' ? j : 1e9));
			fy = max(fy, (int)(island[i][j] == 'X' ? i : 0));
			fx = max(fx, (int)(island[i][j] == 'X' ? j : 0));
		}
	
	for (int i=sy; i<=fy; i++)
	{
		for(int j=sx; j<=fx; j++)
			cout<<(island[i][j] == ' ' ? '.' : island[i][j]);
		cout<<"\n";
	}
	
	return 0;
}
