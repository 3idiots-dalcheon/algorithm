#include <bits/stdc++.h>
using namespace std;

int a, k;
bool bCheck = false;
vector<bool> visited;

int getAnswer(int curr)
{
	if(curr < a) return 1e9;
	else if(curr == a)
	{
		bCheck = true;
		return 0;
	}
	
	int ret = 1e8;
	if(curr%2==0)
		ret = getAnswer(curr/2) + 1;
	if(!bCheck)
		ret = min(ret, getAnswer(curr-1) + 1);
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>a>>k; 
	visited = vector<bool>(k, false);

	cout<<getAnswer(k)<<'\n';
	
	return 0;
}
