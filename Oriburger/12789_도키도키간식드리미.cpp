#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 1;
vector<int> stk;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	while(n--)
	{
		cin>>k;
		if(k == cnt) cnt++;
		else stk.push_back(k);

		while(!stk.empty() && stk.back() == cnt)
		{
			stk.pop_back();	
			cnt++;
		}
	}
	
	if(stk.empty()) cout<<"Nice\n";
	else cout<<"Sad\n";
	
	return 0;
}
