#include<iostream>
#include<algorithm>

using namespace std;

// 가로, 세로, 대각선의 합이 같으면 매직스퀘어
// 매직 스퀘어로 변경하는 최소 비용
// 브루트포스 문제

int arr[3][3];
int result = 1e9;
bool visited[10];

bool check(){
    int sum1 = arr[0][0] + arr[0][1] + arr[0][2];
    int sum2 = arr[1][0] + arr[1][1] + arr[1][2];
    int sum3 = arr[2][0] + arr[2][1] + arr[2][2];

    int sum4 = arr[0][0] + arr[1][0] + arr[2][0];
    int sum5 = arr[0][1] + arr[1][1] + arr[2][1];
    int sum6 = arr[0][2] + arr[1][2] + arr[2][2];

    int sum7 = arr[0][0] + arr[1][1] + arr[2][2];
    int sum8 = arr[2][0] + arr[1][1] + arr[0][2];

    if(sum1 != 15 || sum2 !=15 || sum3 != 15 || sum4 != 15 || sum5 != 15 || sum6 != 15 || sum7 != 15 || sum8 != 15 ) return false;
    return true;
}

void solve(int depth, int cnt){
    if(depth == 9 && check()){
        result = min(result,cnt);
        return;
    }

    int x = depth / 3;
    int y = depth % 3;

    for(int i = 1; i <= 9; i++) {
        if(!visited[i]) {
            int tmp = arr[x][y];
            visited[i] = true;
            arr[x][y] = i;
            solve(depth + 1, cnt + abs(tmp - i));
            visited[i] = false;
            arr[x][y] = tmp;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> arr[i][j];

    solve(0,0);
    cout<<result;
}
