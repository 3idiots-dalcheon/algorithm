#include <bits/stdc++.h>
using namespace std;

int n, st, cnt;
vector<int> bridge;
vector<bool> visited;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n;

	bridge = vector<int>(n+1);
	visited = vector<bool>(n+1, false);
	for(int i=1; i<=n; i++)
		cin>>bridge[i];

	cin>>st;

	queue<int> q;
	q.push(st);
	visited[st] = true;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(int i=-1; i<=1; i+=2)
		{
			int next = cur + bridge[cur] * i;
			if(next <= 0 || next > n) continue;
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}

	for(int i=1; i<=n; i++)
		if(visited[i]) cnt++;
	cout<<cnt<<'\n';

	
	return 0;
}
