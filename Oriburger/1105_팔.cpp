#include <bits/stdc++.h>
using namespace std;

string l, r;
int cnt = 0;
const int chk[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> r;
	int len = min(l.length(), r.length());
	if(l.length() != r.length())
		r = string(l.length(), '9');

	string tmp = "";
	for(int i=0; i<len; i++)
	{
		const int l_sub = stoi(l.substr(0, i+1));
		const int r_sub = stoi(r.substr(0, i+1));
		bool flag = false;
		
		for(int j=0 + (i==0); j<=9; j++)
		{
			tmp += to_string(chk[j]);
			if(l_sub <= stoi(tmp) && stoi(tmp) <= r_sub)
			{
				cnt += (j==9);
				break;
			}
			tmp.pop_back();
		}
	}
	cout<<cnt<<'\n';
	
	return 0;
}
