#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int,int>> adj[101];
int result[101];
int degree[101];
queue<int> q;

// 기본 부품인가 아닌가를 따져야함(기본 or 중간)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;

    cin >> n >> m;

    // 그래프 세팅
    for(int i=0;i<m;i++){
        int x,y,k;
        cin >> x >> y >> k;
        degree[y]++;
        adj[x].push_back({y,k});
    }

    q.push(n);
    result[n]=1;
    vector<int> ans;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(adj[now].empty()){
            ans.push_back(now);
        }

        for(auto next : adj[now]){
            degree[next.first]--;
            result[next.first] += result[now]*next.second;
            if(degree[next.first]==0) q.push(next.first);
        }
    }

    sort(ans.begin(),ans.end());
    for(auto k : ans) cout << k << " " << result[k] << "\n";

}
