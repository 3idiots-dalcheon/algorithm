#include <bits/stdc++.h>
using namespace std;

int n, m, k;
queue<int> q;
vector<int> tmp, bIsStack;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n; 
	bIsStack = vector<int>(n, false);

	for(int i=0; i<n; i++)
		cin>>bIsStack[i];

	for(int i=0; i<n; i++)
	{
		cin>>k;
		if(!bIsStack[i])
			tmp.push_back(k);
	}
	while(!tmp.empty())
	{	
		q.push(tmp.back());
		tmp.pop_back();
	}

	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>k;

		q.push(k);
		k = q.front();
		q.pop();
		
		cout<<k<<" ";
	}
	
	return 0;
}
