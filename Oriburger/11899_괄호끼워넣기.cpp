#include <bits/stdc++.h>
using namespace std;

string str;
vector<char> stk;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>str;

	for(auto &c : str)
	{
		if(stk.empty())
		{
			stk.push_back(c);
		}
		else 
		{
			if(c == ')' && stk.back() == '(')
			{
				stk.pop_back();
			}
			else
				stk.push_back(c);
		}
	}
	cout<<stk.size()<<'\n';
	
	return 0;
}
