#include<iostream>
#include<cstring>
using namespace std;

int w,h,result;
int map[50][50];
bool visited[50][50];
int dx[8]={0,0,-1,1,-1,-1,1,1};
int dy[8]={-1,1,0,0,-1,1,-1,1};

bool check(int x,int y){
    if(x >= 0 && y >= 0 && x < h && y < w) return true;
    return false;
}

void dfs(int x, int y){
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(check(nx,ny) && !visited[nx][ny] && map[nx][ny] == 1) {
            visited[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(1){
        cin >> w >> h;

        if(w == 0 && h == 0) break;

        result = 0;

        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }

        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                if(!visited[i][j] && map[i][j] == 1){
                    visited[i][j] = 1;
                    dfs(i,j);
                    result++;
                }
            }

        cout << result << "\n";

        memset(visited,0,sizeof(visited));
    }



}
