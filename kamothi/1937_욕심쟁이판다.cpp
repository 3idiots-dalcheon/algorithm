#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[500][500];
int dp[500][500];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool check(int x, int y){
    if(x >=0 && y >= 0 && x < n && y < n) return true;
    return false;
}

int dfs(int x ,int y){
    int result = 0;
    if (dp[x][y] >= 0)
        return dp[x][y];

    for(int i=0;i<4;i++){
        if(check(x+dx[i],y+dy[i])){
            if(map[x][y] < map[x+dx[i]][y+dy[i]]){
                int tmp = dfs(x+dx[i],y+dy[i]);
                result = max(result,tmp);
            }
        }
    }

    dp[x][y] = result + 1;

    return result + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result=0;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(dp[i][j] == -1){
                int tmp = dfs(i,j);
                result = max(result,tmp);
            }
        }


    cout << result;
}
