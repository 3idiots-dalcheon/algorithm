#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v,e;
int num = 1;
vector<int> edge[10001];
int pre[10001];
bool result[10001];

int dfs(int node, bool isRoot){
    pre[node] = num++;
    int degree = 0;
    int ret = pre[node];

    for(int i=0;i<edge[node].size();i++){
        int next = edge[node][i];
        if(pre[next] > 0){
            ret = min(ret, pre[next]);
            continue;
        }
        degree++;
        int temp = dfs(next, false);

        if (!isRoot && temp >= pre[node]) {
            result[node] = true;
        }
        ret = min(ret, temp);
    }


    if(isRoot && degree >= 2){
        result[node] = true;
    }

    return ret;

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
        if (pre[i] == 0) dfs(i, true);
    }

    vector<int> a;

    for(int i=1;i<=v;i++){
        if(result[i]) a.push_back(i);
    }

    cout << a.size() << "\n";
    for(int i=0;i<a.size();i++) cout << a[i] << " ";

}
