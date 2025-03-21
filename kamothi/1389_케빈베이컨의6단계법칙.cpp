#include<iostream>

using namespace std;

int n,m;
int cnt=1e9,result;
int g[101][101];
int dist[101][101];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = 1e9;
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int tmp = 0;
        for(int j=1;j<=n;j++){
            tmp += dist[i][j];
        }
        if(tmp < cnt) {
            result = i;
            cnt = tmp;
        }
    }

    cout << result;

}
