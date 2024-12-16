#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int visited[26][26];
int map[26][26];
int n;
int result=1;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<int> ans;


bool check(int x, int y){
    if(x >=0 && x < n && y >=0 && y < n) return true;
    return false;
}

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(check(nx,ny) && !visited[nx][ny] && map[nx][ny] == 1){
            dfs(nx,ny);
            result++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin >> x;
            map[i][j] = x - '0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && map[i][j] == 1){
                dfs(i,j);
                ans.push_back(result);
                result=1;
            }
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << "\n";
}
