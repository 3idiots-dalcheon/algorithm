#include <bits/stdc++.h>
using namespace std;

int n, total = 0;
string str;
vector<int> arr;
unordered_map<string, int> umap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n;
	
	for (int i=1; i<=n; i++)
	{
		cin>>str;
		umap[str] = i;
	}

	for (int i=1; i<=n; i++)
	{
		cin>>str;
		arr.push_back(umap[str]);
	}

	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			total += (arr[i] < arr[j]);
	
	cout<<total<<'/'<<n*(n-1)/2<<'\n';
	
	return 0;
}

