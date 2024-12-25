#include <bits/stdc++.h>
using namespace std;

int n, a, tmp;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	while(n--)
	{
		cin>>a;

		if(!a)
		{
			if(pq.empty()) cout<<"-1\n";
			else
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else
		{
			for(int i=0; i<a; i++)
			{
				cin>>tmp;
				pq.push(tmp);
			}
		}
	}
	
	return 0;
}
