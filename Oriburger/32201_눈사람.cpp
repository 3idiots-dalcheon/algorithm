#include <bits/stdc++.h>
using namespace std;

int n, max_val = -1e9;
string s;
vector<string> ans;
unordered_map<string, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>s;
		mp[s] = i;
	}
	for(int i=0; i<n; i++)
	{
		cin>>s;
		if(mp[s]-i == max_val)
			ans.push_back(s);
		else if(mp[s]-i > max_val)
		{
			max_val = mp[s]-i;
			ans.clear();
			ans.push_back(s);
		}
	}
	for(auto &p : ans)
		cout<<p<<' ';
	
	return 0;
}