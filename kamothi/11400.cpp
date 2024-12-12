#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int v,e;
int num = 0;
vector<int> edge[100001];
int pre[100001];
int par[100001];
int low[100001];
set<pair<int,int>> result;

void dfs(int node){
    pre[node] = low[node] = ++num;


    for(int i=0;i<edge[node].size();i++){
        int next = edge[node][i];
        if(next == par[node]){
            continue;
        }
        if(pre[next] == 0){
            par[next] = node;
            dfs(next);

            if(low[next] > pre[node]) result.insert({min(node, next), max(node, next)});

            low[node] = min(low[node], low[next]);
        }
        else low[node] = min(low[node], pre[next]);
    }


}

// 각 정점을 방문하는 순서를 기록(pre(t) 계산)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for(int i=0;i<e;i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i=1;i<=v;i++) {
        if (pre[i] == 0) dfs(i);
    }



    cout << result.size() << "\n";
    for(auto i : result) cout << i.first << " " << i.second << "\n";

}
