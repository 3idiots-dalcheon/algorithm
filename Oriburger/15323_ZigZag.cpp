#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;
unordered_map<string, string> umap;
vector<int> cnt, cnt2;
vector<string> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	arr = vector<string>(n);
	cnt = cnt2 = vector<int>('z'-'a'+1, 0);
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr.begin(), arr.end());

	for(auto &s : arr)
	{
		string key = s[0] + to_string(cnt[s[0]-'a']);
		cnt[s[0]-'a']++;
		umap[key] = s;
	}

	for(int i=0; i<m; i++)
	{
		cin>>str;
		string key = str[0] + to_string(cnt2[str[0]-'a']);
		cnt2[str[0]-'a'] = (cnt2[str[0]-'a'] + 1) % cnt[str[0]-'a'];
		cout<<umap[key]<<"\n";
	}
	
	return 0;
}

