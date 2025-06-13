#include <bits/stdc++.h>
using namespace std;

int board[5][5];
int dist[5][5];
int r, c, ans = 1e9;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

struct pos{ int y, x; };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&dist[0][0], &dist[4][5], -1);
	
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			cin >> board[i][j];

	cin>>r>>c;
	
	queue<pos> q;
	q.push({r, c});
	dist[r][c] = 0;

	while(!q.empty())
	{
		pos curr = q.front();
		q.pop();

		if(board[curr.y][curr.x] == 1)
		{
			ans = min(ans, dist[curr.y][curr.x]);
		}

		for(int i=0; i<4; i++)
		{
			pos next = {curr.y + dy[i], curr.x + dx[i]};

			if(next.y < 0 || next.y >= 5 || next.x < 0 || next.x >= 5) continue;
			if(board[next.y][next.x] == -1) continue;
			if(dist[next.y][next.x] != -1) continue;

			dist[next.y][next.x] = dist[curr.y][curr.x] + 1;
			q.push(next);
		}
	}

	cout << (ans == 1e9 ? -1 : ans) << '\n';
	
	
	return 0;
}
