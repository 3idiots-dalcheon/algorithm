#include <bits/stdc++.h>
using namespace std;

struct pos{
	int x, y;
};

int n, total_dist = 0, ans; 
vector<pos> arr;
vector<int> dist;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n; 
	arr = vector<pos>(n+1);
	dist = vector<int>(n+1);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i].x>>arr[i].y;
		if(i>0)
		{
			dist[i] = (abs(arr[i].x - arr[i-1].x) 
						+ abs(arr[i].y - arr[i-1].y));
			total_dist += dist[i];
		}
	}

	ans = total_dist;
	for(int i=1; i<n-1; i++)
	{
		int temp = total_dist - dist[i] - dist[i+1];
		temp += abs(arr[i-1].x - arr[i+1].x) 
				+ abs(arr[i-1].y - arr[i+1].y);
		ans = min(ans, temp);
	}

	cout<<ans<<'\n';
	
	return 0;
}

