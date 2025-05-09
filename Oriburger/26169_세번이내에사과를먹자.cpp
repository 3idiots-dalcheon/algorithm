#include <bits/stdc++.h>
using namespace std;
#define VISITED 1e9

int r, c;
int board[5][5];
bool visited[5][5];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool dfs(int y, int x, int cnt, int depth)
{
	if(depth == 3)
	{
		return cnt >= 2;
	}
	
	visited[y][x] = true;
	
	bool ret = false;
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		if(visited[ny][nx] || board[ny][nx] == -1) continue;

		ret |= dfs(ny, nx, cnt + (board[ny][nx] == 1), depth + 1);
		if(ret) return ret;
	}
	visited[y][x] = false;
	
	return ret;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			cin>>board[i][j];

	cin>>r>>c;

	cout<<dfs(r, c, 0, 0);
	
	return 0;
}
