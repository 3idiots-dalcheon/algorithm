#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int> arr;

void getAnswer(int curr, int pos, int sum)
{
	if(curr == n)
	{
		ans += (sum >= m);
		return; 
	}
	
	for(int i=0; i<6; i++)
	{
		getAnswer(curr+1, i%3, (i%3 == pos ? sum+(arr[i]/2) : sum+arr[i]));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	arr = vector<int>(6);
	for(int i=0; i<6; i++)
		cin>>arr[i];

	getAnswer(0, -1, 0);
	cout<<ans<<'\n';
	
	return 0;
}
