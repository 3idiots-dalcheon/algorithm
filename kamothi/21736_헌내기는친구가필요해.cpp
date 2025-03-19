#include<iostream>
#include<queue>

using namespace std;


int n,m,result;
char map[600][600];
bool visited[600][600];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y <m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int,int>> q;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 'I') {
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(check(nx,ny) && map[nx][ny] != 'X' && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = 1;
                if(map[nx][ny] == 'P') result++;
            }
        }

    }

    if(result == 0) cout << "TT";
    else cout << result;
}
