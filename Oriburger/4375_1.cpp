#include <bits/stdc++.h>
using namespace std;

int n, ans;

int solve(int n)
{
	int digit = 1;
	int num = 1;
	
    while(1) 
	{
        if (num % n == 0) break;
        digit++;
        num = num * 10 + 1;
        num %= n;
    }
	return digit;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (!cin.eof())
	{
        cin >> n;
        cout<<solve(n)<<'\n';
	}
	
	return 0;
}
