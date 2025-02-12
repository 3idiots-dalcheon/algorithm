#include <bits/stdc++.h>
using namespace std;

struct word
{
	string s;
	int cnt; 
};

bool comp(const word& a, const word& b)
{
	if(a.cnt != b.cnt) return a.cnt > b.cnt;	
	if(a.s.size() > b.s.size()) return true;
	if(a.s.size() < b.s.size()) return false;
	return a.s < b.s;
}

int n, m; 
unordered_map<string, int> mp;
vector<word> words;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s;
		if(s.length() < m) continue;
		if(mp.find(s) == mp.end()) mp[s] = 1;
		else mp[s]++;
	}
	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		words.push_back({it->first, it->second});
	}
	sort(words.begin(), words.end(), comp);

	for(int i=0; i<words.size(); i++)
		cout<<words[i].s<<'\n';
	
	return 0;
}
