#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const int INF = 9999999;

int n, m, t, ans = INF;
int board[101][101];
P gram_pos;

int BFS(P start, P end)
{
	bool visited[101][101];
	memset(visited, false, sizeof(visited));

	queue<pair<P, int> > q; 
	q.push({start, 0});
	visited[start.first][start.second] = 1;
	
	while(!q.empty())
	{
		P cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		
		if(cur == end)
			return dist;

		for(int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			
			if(ny <= 0 || ny > n || nx <= 0 || nx > m) continue;
			if(visited[ny][nx]) continue;
			if(board[ny][nx] == 1) continue;
			
			visited[ny][nx] = true;
			q.push(make_pair(P(ny, nx), dist + 1));
		}
	}
	return INF; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m>>t; 
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			cin>>board[i][j];
			if(board[i][j] == 2)
				gram_pos = {i, j};
		}

	int a = BFS({1, 1}, {n, m});
	int b = BFS({1, 1}, gram_pos);
	if(b != INF) b += (n - gram_pos.first + m - gram_pos.second);
	ans = min(a, b);
	
	if(ans <= t && ans < INF) cout<<ans<<'\n';
	else cout<<"Fail\n";
	
	return 0;
}
