#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t;

	for(int c = 0; c < t; c++)
	{
		cin>>n;

		unordered_map<string, int> cities;
		unordered_map<int, string> cities_reversed;
		vector<vector<int> > adj = vector<vector<int> >(n+1, vector<int>());
		vector<int> indegree(n+1, 0);
		
		for(int i=0; i<n; i++)
		{
			string u_str, v_str; 
			cin>>u_str>>v_str;
			
			if(cities.count(u_str) == 0)
			{
				cities[u_str] = (int)cities.size();
				cities_reversed[cities[u_str]] = u_str;
			}
			if(cities.count(v_str) == 0)
			{
				cities[v_str] = (int)cities.size();
				cities_reversed[cities[v_str]] = v_str;
			}

			adj[cities[u_str]].push_back(cities[v_str]);
			indegree[cities[v_str]]++;
		}

		int start = -1;
		for(int i=0; i<=n; i++)
		{
			if(indegree[i] == 0)
				start = i;
		}
		
		queue<int> q;
		vector<int> ans;
		q.push(start);
		
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			ans.push_back(u);
			
			for(int v : adj[u])
			{
				indegree[v]--;
				if(indegree[v] == 0)
					q.push(v);
			}
		}

		cout<<"Case #"<<c+1<<": ";
		for(int i=1; i<ans.size(); i++)
		{
			cout<<cities_reversed[ans[i-1]]	<< '-' << cities_reversed[ans[i]] << ' ';
		}
		cout<<"\n";
	}
	
	return 0;
}

