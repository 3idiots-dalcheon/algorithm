#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<float> drink;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	drink = vector<float>(n);
	for(int i=0; i<n; i++)
		cin>>drink[i];
	sort(drink.begin(), drink.end(), greater<float>());

	while(drink.size() > 1)
	{
		drink[0] += drink.back() / 2.0f;
		drink.pop_back();
	}
	
	cout<<drink.back()<<'\n';
	
	return 0;
}
