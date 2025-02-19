#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1)
	{
		int n, ans=0, cnt=0;
		cin>>n;
		if(n==0) break;

		mp.clear();
		for(int i=0; i<n; i++)
		{
			vector<int> arr(5);
			for(int j=0; j<5; j++) cin>>arr[j];
			sort(arr.begin(), arr.end());

			string s;
			for(int j=0; j<5; j++) s+=to_string(arr[j]);
			cnt = max(cnt, ++mp[s]);
		}
		
		for(auto it:mp)
		{
			if(it.second==cnt) ans += it.second;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
