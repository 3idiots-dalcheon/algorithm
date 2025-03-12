#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, ans;
vector<int> cal;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>a>>b>>c;

	cal = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>cal[i];

	sort(cal.begin(), cal.end(), greater<int>());

	float sum = c;
	ans = (int)floor(sum/a);
	for(int i=0; i<n; i++)
	{
		float price = a+b*(i+1);
		sum += cal[i];
		ans = max(ans, (int)floor(sum/price)); 
	}
	cout<<ans<<'\n';
	
	return 0;
}

