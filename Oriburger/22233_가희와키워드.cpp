#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;
unordered_set<string> uset;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		cin>>str;
		uset.insert(str);
	}
	for(int i=0; i<m; i++)
	{
		cin>>str;

		while(!str.empty())
		{
			int comma = str.find(',');
			string s = (comma == string::npos ? str : str.substr(0, comma));
			str = (comma == string::npos ? "" : str.substr(comma+1));
			
			if(uset.find(s) != uset.end())
				uset.erase(s);
		}
		
		cout<<uset.size()<<"\n";
	}
	
	return 0;
}
