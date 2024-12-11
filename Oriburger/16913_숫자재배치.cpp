#include <bits/stdc++.h>
using namespace std;

int a, b, ans = -1;
string a_str, b_str;
vector<bool> picked;

int getAnswer(string curr)
{
	if(curr.size() == a_str.size())
	{
		return stoi(curr) < b ? stoi(curr) : -1;
	}

	int ret = -1;
	for(int i = 0; i < a_str.size(); i++)
	{
		if(picked[i]) continue;
		picked[i] = true;
		ret = max(ret, getAnswer(curr + a_str[i]));
		picked[i] = false;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	a_str = to_string(a);
	b_str = to_string(b);
	
	picked = vector<bool>(a_str.size(), false);
	
	for(int i=0; i<a_str.size(); i++)
	{
		if(a_str[i] == '0') continue;
		string tmp; tmp.push_back(a_str[i]); 
		
		picked[i] = true;
		ans = max(ans, getAnswer(tmp));
		picked[i] = false;
	}
	cout<<ans<<'\n';
	
	return 0;
}
