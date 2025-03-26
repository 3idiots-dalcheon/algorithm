#include <bits/stdc++.h>
using namespace std;

string getAnswer(int r, int c)
{
	string str = "";

	while(c >= 1)
	{
		str += char((c - 1) % 26  + 'A');
		c = (c-1) / 26;
	}
	reverse(str.begin(), str.end());
	str += to_string(r);
	return str;
}

int main()
{
	int r, c;
	char tmp;
	
	while(1)
	{
		scanf("%c%d%c%d", &tmp, &r, &tmp, &c);
		if(r == 0 && c == 0) break;
		getchar();
		printf("%s\n", getAnswer(r, c).c_str());
	}
	
	return 0;
}

