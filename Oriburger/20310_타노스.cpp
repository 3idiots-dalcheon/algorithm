#include <bits/stdc++.h>
using namespace std;

string getAnswer(string s)
{
	int arr[2] = {0, 0};
	for(auto &p : s)
		arr[p-'0']++;

	arr[1] /= 2; arr[0] /= 2;
	
	while(arr[1] != 0)
	{
		for(int i=0; i<s.length(); i++)
		{
			if(s[i] == '1')
			{
				s.erase(i, 1);
				arr[1]-=1;
				break;
			}		
		}
	}

	while(arr[0] != 0)
	{
		for(int i=0; i<s.length(); i++)
		{
			if(s[s.length()-i-1] == '0')
			{
				s.erase(s.length()-i-1, 1);
				arr[0]-=1;
				break;
			}		
		}
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin>>s;
	cout<<getAnswer(s);
	
	return 0;
}
