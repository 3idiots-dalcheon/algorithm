#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > pooling(int size, vector<vector<int> > &arr)
{
	if(arr.size() == 1) return arr;
	
	vector<vector<int> > res;
	for(int i = 0; i < arr.size(); i += size)
	{
		vector<int> temp;
		for(int j = 0; j < arr[0].size(); j += size)
		{
			vector<int> temp2;
			for(int k = 0; k < size; k++)
			{
				for(int l = 0; l < size; l++)
				{
					temp2.push_back(arr[i+k][j+l]);
				}
			}
			sort(temp2.begin(), temp2.end(), greater<int>());
			temp.push_back(temp2[1]);
		}
		res.push_back(temp);
	}
	return res;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; 
	vector<vector<int> > adj;
	cin >> n;
	
	adj = vector<vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];

	while(1)
	{
		adj = pooling(2, adj);
		if(adj.size() == 1) break;
	}
	cout<<adj[0][0]<<endl;
	
	return 0;
}
