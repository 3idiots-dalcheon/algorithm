#include <bits/stdc++.h>
using namespace std;

string s;
int n, m, k;

vector<int> arr;
unordered_map<int, string> umap;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	arr.resize(n);
	for(int i=0; i<n; i++)
	{
		cin>>s>>k;
		umap[i] = s;
		arr[i] = k;
	}

	for(int i=0; i<m; i++)
	{
		cin>>k;
		int pos = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
		cout<<umap[pos]<<"\n";
	}
	
	return 0;
}
