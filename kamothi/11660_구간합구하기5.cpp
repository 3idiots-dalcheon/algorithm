#include<iostream>

using namespace std;

int dp[1025][1025];
int dp2[1025][1025];
int arr[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            dp2[i][j] = arr[i][j] + dp2[i][j-1];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j] + dp2[i][j];
        }
    }

    while(m--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] + dp[x1-1][y1-1] - dp[x1-1][y2] - dp[x2][y1-1] << "\n";
    }
}
