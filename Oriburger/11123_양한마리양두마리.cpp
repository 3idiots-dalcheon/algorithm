#include <bits/stdc++.h>
using namespace std;

int t, h, w;
char board[101][101];
bool visited[101][101];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

void DFS(int y, int x)
{
	visited[y][x] = true;
	for(int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if(visited[ny][nx] || board[ny][nx] != '#') continue;
		DFS(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>h>>w;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				cin>>board[i][j];

		int ans = 0;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
			{
				if(board[i][j] != '#' || visited[i][j]) continue;
				DFS(i, j);
				ans += 1;
			}
		cout<<ans<<'\n';
		
		memset(visited, false, sizeof(visited));
	}
	
	return 0;
}
