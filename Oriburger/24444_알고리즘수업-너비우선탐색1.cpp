#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<vector<int> > adj;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r; 

	adj.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//sort 
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	//bfs
	queue<int> q;
	vector<int> order(n + 1, 0);
	q.push(r);
	int k = 1;
	order[r] = k;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : adj[cur])
		{
			if (order[next] == 0)
			{
				order[next] = ++k;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << order[i] << "\n";
	
	return 0;
}
