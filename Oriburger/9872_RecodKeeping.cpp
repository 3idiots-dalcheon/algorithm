#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
unordered_map<string, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		vector<string> arr = vector<string>(3);
		for(int j=0; j<3; j++)
			cin>>arr[j];
		sort(arr.begin(), arr.end());		

		arr[0] = arr[0] + arr[1] + arr[2];
		mp[arr[0]]++;

		ans = max(ans, mp[arr[0]]);
	}
	cout<<ans<<'\n';
	
	return 0;
}
