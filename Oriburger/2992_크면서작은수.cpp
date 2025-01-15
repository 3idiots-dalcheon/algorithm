#include <bits/stdc++.h>
using namespace std;

string s, tmp;
int ans = 0, s_num = 0;
vector<bool> picked;

int getAnswer(string curr)
{
	if(curr.size() == s.size())
	{
		int k = stoi(curr);
		if(k <= s_num) return 1e9;
		return k;
	}

	int ret = 1e9; 
	for(int i=0; i<(int)s.size(); i++)
	{
		if(picked[i]) continue;
		picked[i] = true;
		ret = min(ret, getAnswer(curr + s[i]));
		picked[i] = false;
	}
	return ret; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>s;
	s_num = stoi(s);
	picked = vector<bool>((int)s.size(), false);

	tmp = s; 
	sort(tmp.begin(), tmp.end(), greater<char>());
	
	ans = (tmp == s ? 0 : getAnswer(""));
	cout<<ans<<'\n';
	
	return 0;
}
