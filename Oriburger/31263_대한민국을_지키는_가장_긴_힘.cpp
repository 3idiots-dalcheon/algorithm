#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<int> cache;

int solve(int idx)
{
	if(idx >= n) return 0;
	int& ret = cache[idx];
	if(ret != -1) return ret;
	
	ret = 1e9;
	
	for(int i=3; i>=1; i--)
	{
		string ss = str.substr(idx, i);
		int num = stoi(ss);	

		if(ss[0] == '0') continue;
		if(num <= 641 && num > 0 )
		{
			ret = min(ret, solve(idx+i) + 1);
		}
	}
	return ret;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>str;
	cache = vector<int>(n, -1);

	cout<<solve(0)<<'\n';
	
	return 0;
}
