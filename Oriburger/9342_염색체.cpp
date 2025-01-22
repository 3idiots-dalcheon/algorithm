#include <bits/stdc++.h>
using namespace std;

int t;

bool isInfected(string str)
{
	if(str.front() < 'A' || str.front() > 'F'
		|| str.back() < 'A' || str.back() > 'F') return false;

	const char ch[3] = { 'A', 'F', 'C' };
	int sIdx = str[0] == 'A' ? 0 : 1;

	for(int cIdx = 0; cIdx < 3; cIdx++)
	{
		if(str[sIdx] != ch[cIdx]) return false;
		while(str[sIdx] == ch[cIdx] && sIdx <= str.size() - 1) sIdx++;
	}
	return sIdx == (int)str.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t;

	while(t--)
	{
		string str; 
		cin>>str; 

		if(isInfected(str))
			cout<<"Infected!\n";
		else
			cout<<"Good\n";
	}
	
	return 0;
}
