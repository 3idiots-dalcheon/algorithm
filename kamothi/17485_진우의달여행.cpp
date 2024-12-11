#include<iostream>
#include<algorithm>

using namespace std;

// 0은 왼쪽 위, 1은 위, 2는 오른쪽 위
int dp[1002][1002][3];
int n,m;
int map[1002][1002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> map[i][j];

    for(int i=1;i<=m;i++){
        dp[1][i][0] = map[1][i];
        dp[1][i][1] = map[1][i];
        dp[1][i][2] = map[1][i];

    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(j==1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = dp[i-1][j][2] + map[i][j];
                dp[i][j][2] = min(dp[i-1][j+1][0],dp[i-1][j+1][1]) + map[i][j];
                continue;
            }
            if(j==m){
                dp[i][j][0] = min(dp[i-1][j-1][1],dp[i-1][j-1][2]) + map[i][j];
                dp[i][j][1] = dp[i-1][j][0] + map[i][j];
                dp[i][j][2] = 0;
                continue;
            }
            dp[i][j][0] = min(dp[i-1][j-1][1],dp[i-1][j-1][2]) + map[i][j];
            dp[i][j][1] = min(dp[i-1][j][0],dp[i-1][j][2]) + map[i][j];
            dp[i][j][2] = min(dp[i-1][j+1][0],dp[i-1][j+1][1]) + map[i][j];
        }

    int result = 1e9;
    for(int i=1;i<=m;i++){
        if(i==1){
            result = min({result, dp[n][i][1],dp[n][i][2]});
            continue;
        }
        if(i==m){
            result = min({result,dp[n][i][0],dp[n][i][1]});
            continue;
        }
        result = min({result,dp[n][i][0],dp[n][i][1],dp[n][i][2]});
    }

    cout << result;

}
