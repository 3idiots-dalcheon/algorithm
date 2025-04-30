#include <bits/stdc++.h>
using namespace std;

int n, ans;

int solve(int n)
{
	int digit, num;
	digit = num = 1;
	
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
	while (scanf("%d", &n) != EOF)
	{
        printf("%d\n", solve(n));
	}
	
	return 0;
}
