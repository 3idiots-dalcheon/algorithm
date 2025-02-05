#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<pair<int,int>> v;

    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);

    for(int i=1;i<n;i++){
        if(pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
    }

    cout << pq.size();
}
