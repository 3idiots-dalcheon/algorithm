#include <bits/stdc++.h>
using namespace std;

int k, ans = -1; 
vector<int> arr, cache;

int getAnswer(int idx)
{
	int& ret = cache[idx];
	if(idx == k-1) return ret = 1;
	if(ret != -1) return ret;

	ret = 1;
	for(int i = idx+1; i < k; i++)
	{
		if(arr[idx] <= arr[i]) continue;
		ret = max(ret, getAnswer(i) + 1);
	}
	return ret; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>k;
	arr = cache = vector<int>(k, -1);
	for(int i=0; i<k; i++)
		cin>>arr[i];

	for(int i=0; i<k; i++)
		ans = max(ans, getAnswer(i));
	cout<<k - ans<<'\n';
	
	return 0;
}
