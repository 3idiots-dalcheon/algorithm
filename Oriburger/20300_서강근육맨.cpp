#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0; 
vector<long long> t;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	t = vector<long long>(n);

	for(int i=0; i<n; i++)
		cin>>t[i];

	sort(t.begin(), t.end());

	if(n%2 == 1)
	{
		ans = t.back();
		t.pop_back();
		n--;
	}
	
	for(int i=0; i<n/2; i++)
	{
		cout<<t[i]<<','<<t[n-1-i]<<'\n';
		ans = max(ans, t[i]+t[n-1-i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}
