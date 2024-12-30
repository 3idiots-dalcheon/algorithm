#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
vector<int> arr, idxList;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>k; 

	arr = vector<int>(n);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		idxList.push_back(i);
	}

	do
	{
		int total = 500;
		for(auto &i : idxList)
		{
			total = total + arr[i] - k;
			if(total < 500) break;
		}
		ans += (total >= 500);
	}while(next_permutation(idxList.begin(), idxList.end()));

	cout<<ans<<'\n';
	
	return 0;
}
