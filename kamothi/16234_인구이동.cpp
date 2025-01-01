#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int n,l,r;
int arr[50][50];
bool visited[50][50];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int result,ans;
vector<pair<int,int>> vp;

void dfs(int x, int y){
    vp.push_back({x,y});
    visited[x][y] = true;
    result += arr[x][y];

    for(int i = 0 ; i < 4 ; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n || visited[nextX][nextY]) continue;
        if(abs(arr[nextX][nextY] - arr[x][y]) < l || abs(arr[nextX][nextY] - arr[x][y]) > r) continue;
        dfs(nextX, nextY);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> l >> r;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> arr[i][j];
    }

    while(1){
        memset(visited,false,sizeof(visited));
        int tmp=0;
        vector<pair<pair<int,int>,int>> v;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if (!visited[i][j]) {
                    vp.clear();
                    result = 0;

                    dfs(i, j);

                    if (vp.size() == 1) {
                        visited[i][j] = false;
                        tmp++;
                        continue;
                    }

                    int num = result / vp.size();
                    for (int k = 0; k < vp.size(); k++) {
                        v.push_back({{vp[k].first, vp[k].second}, num});
                    }
                }
            }
        }

        if(tmp == n * n) break;

        for(int i = 0 ; i < v.size() ; i++) {
            int x = v[i].first.first;
            int y = v[i].first.second;
            int num = v[i].second;

            arr[x][y] = num;
        }

        ans++;
    }

    cout << ans;

}
