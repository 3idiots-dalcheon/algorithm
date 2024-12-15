#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> problem[32001];
int degree[32001];
priority_queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        problem[a].push_back(b);
        degree[b]++;
    }
    for(int i=1;i<=n;i++)
        if(degree[i] == 0) q.push(-i);


    while(!q.empty()){
        int now = -q.top();
        cout << now << " ";
        q.pop();

        for(auto next : problem[now]){
            degree[next]--;

            if(degree[next] == 0){
                q.push(-next);
            }
        }
    }


}
