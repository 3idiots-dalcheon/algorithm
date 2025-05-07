#include <bits/stdc++.h>
using namespace std;

int n, max_len = -1;
vector<string> arr;
vector<vector<int> > dotPos;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;

	arr.resize(n);
	dotPos.resize(n);
	for(int i=0; i<n; i++)
	{
		while(1)
		{
			int x; cin>>x;
			if(x==-1) break;
			arr[i] += to_string(x);
			arr[i].push_back(',');
			dotPos[i].push_back((int)arr[i].size()-1);
		}
		max_len = max(max_len, (int)arr[i].size());
	}

	for(int i=0;i<n;i++)
	{
		while((int)arr[i].size()<max_len)
		{
			arr[i] += "0,";
			dotPos[i].push_back((int)arr[i].size()-1);
		}
	}

	for(int k=1; k<=max_len; k++)
	{
		unordered_set<string> uset;
		bool flag = false;
		for(int i=0; i<n; i++)
		{
			string tmp = arr[i].substr(0, dotPos[i][k-1]);

			if(uset.find(tmp)!=uset.end())
			{
				flag = true;
				continue;
			}
			uset.insert(tmp);
		}
		if(!flag)
		{
			cout<<k<<'\n';
			break;
		}
	}
	
	
	return 0;
}
