#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visited[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,result=0;
    cin >> n >> m;

    vector<int> v[501];

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = 1;

    while(!q.empty()){
        int next = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cnt > 1) continue;

        for(int i=0;i<v[next].size();i++){
            if(!visited[v[next][i]]){
                visited[v[next][i]] = 1;
                result++;
                q.push({v[next][i],cnt+1});
            }
        }
    }

    cout << result;
}
