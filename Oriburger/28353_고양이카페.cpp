#include <bits/stdc++.h>
using namespace std;

int n, k, p, q, ans = 0;
vector<int> w;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k; 

	w = vector<int>(n);
	for(int i=0; i<n; i++) cin>>w[i];

	sort(w.begin(), w.end());

	p = 0, q = n-1;
	while(p<q)
	{
		if(w[p] + w[q] > k)	q--;
		else
		{
			ans += 1; 
			p++, q--;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
