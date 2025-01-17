#include <bits/stdc++.h>
using namespace std;

int n, x, ans = 0, cnt = 0;
vector<int> arr, sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>x;
	
	arr = sum = vector<int>(n+1, 0);
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	for(int i=1; i<=n; i++)
		sum[i] = sum[i-1] + arr[i];

	for(int i=0; i<=n-x; i++)
	{
		if(ans < sum[i+x] - sum[i])
		{
			ans = sum[i+x] - sum[i];
			cnt = 1;
		}
		else if(ans == sum[i+x] - sum[i])
		{
			cnt += 1;
		}
	}
	
	if(ans > 0)
	{
		cout<<ans<<'\n';
		cout<<cnt<<'\n';
	}
	else
	{
		cout<<"SAD\n";
	}
	
	return 0;
}
