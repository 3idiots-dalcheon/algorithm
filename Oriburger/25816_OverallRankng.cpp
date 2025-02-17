#include <bits/stdc++.h>
using namespace std;

int n;
map<string, pair<int, float> > mp;
vector<pair<float, string> > arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=1; i<=n; i++)
	{
		string s; cin>>s;
		if(mp.find(s) == mp.end()) mp[s] = {1, i};
		else mp[s] = {mp[s].first + 1, mp[s].second + i};
	}

	for(auto it=mp.begin(); it!=mp.end(); it++)
	{
		arr.push_back(make_pair(it->second.second / it->second.first, it->first));	
	}

	sort(arr.begin(), arr.end());
	for(auto &p : arr) cout<<p.second<<"\n";
	
	return 0;
} 
