#include <bits/stdc++.h>
using namespace std;

int n, x, cnt;
vector<int> arr;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	arr = vector<int>(n);

	for(int i=0; i<n; i++)
		cin>>arr[i];
	cin>>x;

	sort(arr.begin(), arr.end());

	for(int i=0; i<n; i++)
	{
		auto iter = lower_bound(arr.begin() + i + 1, arr.end(), x - arr[i]);
		while(iter != arr.end() && *iter == x - arr[i])
		{
			cnt++;
			iter++;
		}
	}

	cout<<cnt<<'\n';
	
	return 0;
}
