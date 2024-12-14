#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

// scc 같은 문제
// 결국 같은 컴포넌트끼리는 쓰러짐

int t,n,m;
vector<int> edge[100001];
vector<int> redge[100001];
stack<int> s;
int indegree[100001];
int scc[100001];
int visited[100001];


void dfs(int node){
    visited[node] = true;
    for(auto next : edge[node]){
        if(!visited[next]){
            dfs(next);
        }
    }
    s.push(node);
}

void dfs2(int node, int idx){
    scc[node] = idx;
    for(auto next : redge[node]){
        if(!scc[next]){
            dfs2(next,idx);
        }
        else if(scc[next] != scc[node]){
            indegree[scc[node]]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n >> m;
        int result=0;


        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
            redge[b].push_back(a);
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]) dfs(i);
        }


        int idx = 1;

        while(!s.empty()){
            int next = s.top();
            s.pop();
            if(!scc[next]) {
                scc[next] = idx;
                dfs2(next,idx);
                idx++;
            }
        }

        for(int i=1;i<idx;i++){
            if(indegree[i] == 0) {
                result++;
            }
        }

        cout << result << "\n";

        for (int i = 0; i < 100001; ++i) {
            edge[i].clear();
            redge[i].clear();
            indegree[i] = 0;
            scc[i] = 0;
            visited[i] = 0;
        }
    }
}
