#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int Time[10001];
vector<int> work[10001];
int result[10001];
int degree[10001];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    // 그래프 세팅
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> Time[i];
        result[i] = Time[i];
        cin >> tmp;
        for (int j = 1; j <= tmp; j++) {
            int k;
            cin >> k;
            degree[i]++;
            work[k].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
        if(degree[i] == 0) q.push(i);


    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto next : work[now]){
            degree[next]--;

            result[next] = max(result[next],result[now]+Time[next]);

            if(degree[next] == 0){
                q.push(next);
            }
        }
    }


    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, result[i]);
    }
    cout << ans;


}
