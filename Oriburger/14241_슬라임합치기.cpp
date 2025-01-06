#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>k;
		pq.push(k);
	}
	while(pq.size() != 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		ans += a*b;
		pq.push(a+b);
	}
	cout<<ans<<'\n';
	
	return 0;
}