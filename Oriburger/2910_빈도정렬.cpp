#include <bits/stdc++.h>
using namespace std;

struct info{
	int num;
	int order;
	int cnt; 
};

bool comp(const info& a, const info& b)
{
	if(a.cnt == b.cnt)
		return a.order < b.order;
	return a.cnt > b.cnt;
}

int n, c, tmp, cnt = 0;
unordered_map<int, pair<int, int> > umap;
vector<info> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>c;

	
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		if(umap.count(tmp) == 0)
			umap[tmp] = {cnt++, 1};
		else
			umap[tmp].second += 1;
	}

	for (auto& it : umap) 
	{
		arr.push_back({it.first, it.second.first, it.second.second});
	}

	sort(arr.begin(), arr.end(), comp);

	for(auto& p : arr)
	{
		for(int i=0; i<p.cnt; i++)
			cout<<p.num<<" ";
	}
	
	return 0;
}
