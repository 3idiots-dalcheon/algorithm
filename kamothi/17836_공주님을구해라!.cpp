#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m,t;
int map[101][101];
int visited[101][101][2];
int result = 1e9;

bool check(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m >> t;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> map[i][j];

    // 위치, 시간, 유무
    queue<pair<pair<int,int>,pair<int,bool>>> q;
    q.push({{0,0},{0,0}});

    memset(visited, -1, sizeof(visited));
    visited[0][0][0] = 0;

    while(!q.empty()){
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;

        int nowT = q.front().second.first;
        int nowB = q.front().second.second;

        q.pop();

        if(nowT > t) continue;
        if(nowX == n-1 && nowY == m-1) {
            result = min(result,nowT);
            continue;
        }


        for(int i=0;i<4;i++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            bool nextB = false;
            if(map[nextX][nextY] == 2 || nowB) nextB = true;

            if(check(nextX,nextY)){
                if(nowB || map[nextX][nextY] != 1) {
                    if(visited[nextX][nextY][nextB] == -1){
                        q.push({{nextX, nextY}, {nowT+1, nextB}});
                        visited[nextX][nextY][nextB] = nowT+1;
                    }
                }
            }
        }
    }
    if(result == 1e9) {
        cout << "Fail";
        return 0;
    }
    cout << result;
    return 0;

}
