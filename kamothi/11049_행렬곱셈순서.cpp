#include<iostream>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int mat[501][2];
    int dp[501][501];

    for(int i=1;i<=n;i++){
        cin >> mat[i][0] >> mat[i][1];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = 0;

    for(int s = 1; s < n; s++){
        for(int i = 1; i <= n-s; i++){
            dp[i][i+s] = INT_MAX;
            for(int k = i; k <= i+s-1; k++){
                dp[i][i+s] = min(dp[i][i+s],
                                 dp[i][k] + dp[k+1][i+s] + mat[i][0] * mat[k+1][0] * mat[i+s][1]);
            }
        }
    }
    cout << dp[1][n];
}
