#include<iostream>

using namespace std;

// 오른쪽 or 아래쪽
// 탐색할 수 있는 최대 자원수
// 왼쪽과 위쪽만 알고 있으면 된다.

int n,m;
int map[301][301];
int dp[301][301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        }


    cout << dp[n][m];

}
