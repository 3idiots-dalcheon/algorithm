#include<iostream>
#include<algorithm>

using namespace std;


int n;
int result;
bool visited[100][100];
int arr[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool check(int x, int y){
    if(x >= 0 && y >=0 && x < n && y < n) return true;
    return false;
}

void dfs(int nowX, int nowY, int h){
    visited[nowX][nowY] = 1;

    for(int i=0;i<4;i++){
        int nextX = nowX + dx[i];
        int nextY = nowY + dy[i];

        if(check(nextX,nextY) && !visited[nextX][nextY] && arr[nextX][nextY] > h) dfs(nextX,nextY,h);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin >> arr[i][j];


    for(int k=0;k<=100;k++){
        int tmp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && arr[i][j] > k){
                    dfs(i,j,k);
                    tmp++;
                }
            }
        }


        result = max(result,tmp);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) visited[i][j] = false;
    }

    cout << result;


}
