#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<char> arr;
deque<char> deq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t; 

	while(t--)
	{
		cin>>n;
		arr = vector<char>(n);

		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
			if(i==0)
			{
				deq.push_back(arr[i]);
			}
			else
			{
				if(arr[i] <= deq.front())
					deq.push_front(arr[i]);
				else
					deq.push_back(arr[i]);
			}
		}

		for(auto &it : deq)
			cout<<it;
		cout<<"\n";
		deq.clear();
	}
	
	return 0;
}
