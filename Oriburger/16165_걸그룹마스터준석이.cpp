#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, vector<string> > idol;
unordered_map<string, string> idol2;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	int tmp;
	for(int i=0; i<n; i++)
	{
		string group;
		cin>>group>>tmp;

		vector<string> names = vector<string>(tmp);
		for(int j=0; j<tmp; j++)
		{
			cin>>names[j];
			idol2[names[j]] = group;
		}	
		sort(names.begin(), names.end());
		idol[group] = names;
	}

	
	
	while(m--)
	{
		string q; int k;
		cin>>q>>k;
		if(k==0)
		{
			vector<string> names = idol[q];
			for(auto &s : names)
				cout<<s<<'\n';
		}
		else
		{
			cout<<idol2[q]<<'\n';
		}
	}
	
	return 0;
}
