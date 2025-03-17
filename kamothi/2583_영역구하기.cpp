#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int m,n,k;
bool visited[100][100];
int map[100][100];
vector<int> result;
queue<pair<int,int>> q;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int x, int y){
    if(x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}

int bfs(){
    int cnt=0;
    while(!q.empty()){
        int x=q.front().second;
        int y=q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!check(nx,ny)) continue;
            if(!map[ny][nx]){
                cnt++;
                map[ny][nx]=1;
                q.push({ny,nx});
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    int area[100], cnt=0;

    for(int i=0;i<k;i++){
        // 왼쪽 아래, 오른쪽 위
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1;i<y2;i++){
            for(int j=x1;j<x2;j++){
                map[i][j] = 1;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!map[i][j]){
                q.push({i,j});
                area[cnt++]=bfs();
                if(!area[cnt-1])area[cnt-1]=1;
            }
        }
    }
    sort(area,area+cnt);
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++) cout << area[i] << " ";
}
