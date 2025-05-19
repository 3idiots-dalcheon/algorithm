#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, m;
int board[301][301];
bool visited[301][301];
const int dy[2] = {1, 0};
const int dx[2] = {0, 1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>m>>n;
	memset(visited, false, sizeof(visited));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];

	queue<P> q;
	q.push({0, 0});
	visited[0][0] = true;

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		for(int i=0; i<2; i++)
		{
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if(ny >= n || nx >= m) continue;
			if(visited[ny][nx]) continue;
			if(board[ny][nx] == 0) continue;

			visited[ny][nx] = true;
			q.push({ny, nx});
		}
	}
	if(visited[n-1][m-1]) cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}
