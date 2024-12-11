#include<iostream>
#include<queue>
#include<set>
#include<string>

using namespace std;

// 현재 그래프의 상태 자체가 노드가 된다.
set<string> visited;

string now;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int x, int y){
    if(x >=0 && x <3 && y >=0 && y<3) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char tmp;
            cin >> tmp;
            now += tmp;
        }
    }


    queue<pair<string,int>> q;
    q.push({now,0});
    visited.insert(now);

    while(!q.empty()){
        string cur = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        if(cur == "123456780") {
            cout << cur_cnt;
            return 0;
        }

        int tmp = cur.find('0');
        int x = tmp/3;
        int y = tmp%3;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check(nx,ny)){
                string next = cur;
                swap(next[x*3+y],next[nx*3+ny]);
                if(visited.find(next) == visited.end()){
                    visited.insert(next);
                    q.push({next,cur_cnt+1});
                }
            }
        }
    }


    cout << -1;
    return 0;

}
